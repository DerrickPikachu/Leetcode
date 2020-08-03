class Solution {
public:
    int longestWPI(vector<int>& hours) {
        vector<int> dp(hours.size(), 0);
        
        dp[0] = (hours[0] > 8)? 1:-1;
        
        for (int i=1; i<hours.size(); i++)
            dp[i] = (hours[i] > 8)? dp[i-1] + 1:dp[i-1] - 1;
        if (dp.back() > 0)
            return dp.size();
        
        for (int l=dp.size() - 1; l>0; l--) {
            for (int i=0; i<=dp.size() - l; i++) {
                if (i == 0 && dp[l-1] > 0)
                    return l;
                else if (i > 0 && dp[i+l-1] - dp[i-1] > 0)
                    return l;
            }
        }
        
        return 0;
    }
};
