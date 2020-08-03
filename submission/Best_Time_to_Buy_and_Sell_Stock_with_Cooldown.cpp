class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        vector<int> dp(prices.size());
        dp[0] = 0;
        
        for (int i=1; i<prices.size(); i++) {
            dp[i] = dp[i-1];
            for (int j=i-1; j>=0; j--) {
                int num = (j < 2)? prices[i] - prices[j]:prices[i] - prices[j] + dp[j
                    -2];
                if (dp[i] < num)
                    dp[i] = num;
            }
        }
        
        return dp[prices.size()-1];
    }
};
