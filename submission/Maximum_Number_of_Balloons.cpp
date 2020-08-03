class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mp;
        string ball = "balloon";
        int res = 0;
        
        for (int i=0; i<text.size(); i++)
            mp[text[i]]++;
        
        int i = 0;
        while (mp[ball[i]] != 0) {
            i = 0;
            
            for (; ; i++) {
                if (mp[ball[i]] == 0)
                    break;
                
                if (i == ball.size() - 1) {
                    res++;
                    break;
                }
                mp[ball[i]]--;
            }
        }
        
        return res;
    }
};
