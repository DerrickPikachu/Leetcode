class Solution {
public:
    int numSub(string s) {
        vector<int> preCal(s.size() + 1, 0);
        int mod = pow(10, 9) + 7, res = 0;
        string tem = "";
        
        for (int i = 1; i <= s.size(); i++)
            preCal[i] = (preCal[i-1] + i) % mod;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1')
                tem.push_back(s[i]);
            else {
                res += preCal[(int)tem.size()];
                tem.clear();
            }
        }
        
        res += preCal[(int)tem.size()];
        
        return res;
    }
};
