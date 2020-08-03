class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size()-1,len=0;
        if (s.empty())  return 0;
        
        while (s[i] == ' ') {
            s.pop_back();
            i--;
        }
        for (; i>=0; i--) {
            if (s[i] == ' ')
                return len;
            else
                len++;
        }
        
        return len;
    }
};
