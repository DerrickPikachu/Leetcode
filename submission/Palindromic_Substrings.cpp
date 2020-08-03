class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<int>> valid(s.size() + 1, vector<int>(s.size(), 0));
        int res = 0;
        
        for (int i=0; i<s.size(); i++) {
            valid[1][i] = 1;
            valid[0][i] = 1;
            res++;
        }
        
        for (int l=2; l<=s.size(); l++) {
            for (int i=l-1; i<s.size(); i++) {
                int leftEnd = i - l + 1;
                
                if (s[leftEnd] == s[i] && valid[l-2][i-1]) {
                    res++;
                    valid[l][i] = 1;
                }
            }
        }
        
        return res;
    }
};
