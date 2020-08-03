class Solution {
public:
    int minFlipsMonoIncr(string s) {
        vector<int> dp(2);
        if (s[0] == '1') {
            dp[0] = 1;
            dp[1] = 0;
        }
        else {
            dp[0] = 0;
            dp[1] = 1;
        }
        
        for (int i=1; i<s.size(); i++) {
            int next0, next1;
            next0 = dp[0];
            next1 = min(dp[0], dp[1]);
            
            if (s[i] == '0')
                next1++;
            else
                next0++;
            
            dp[0] = next0;
            dp[1] = next1;
        }
        
        return min(dp[0], dp[1]);
    }
};
