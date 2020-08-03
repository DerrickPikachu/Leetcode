class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> sell(prices.size()), buy(prices.size());
        
        sell[0] = 0;
        buy[0] = -prices[0];
        
        for (int i=1; i<prices.size(); i++) {
            sell[i] = max(prices[i] + buy[i-1] - fee, sell[i-1]);
            buy[i] = max(buy[i-1], sell[i-1] - prices[i]);
        }
        
        return sell.back();
    }
};
