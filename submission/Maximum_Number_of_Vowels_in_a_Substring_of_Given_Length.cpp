class Solution {
public:
    int maxVowels(string s, int k) {
        queue<char> window;
        int res = 0, subNum = 0;
        unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
        
        for (char& c : s) {
            window.push(c);
            
            if (window.size() > k) {
                char front = window.front();
                window.pop();
                if (vowel.count(front))
                    subNum--;
            }
            
            if (vowel.count(c))
                subNum++;
            res = max(res, subNum);
        }
        
        return res;
    }
};
