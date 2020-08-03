class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size() + 1, 0);
        int pass7 = 0, pass30 = 0;
        days.insert(days.begin(), 0);
        
        for (int i=1; i<days.size(); i++) {
            int buy1, buy7, buy30;
            
            buy1 = dp[i-1] + costs[0];
            while (days[i] - days[pass7+1] >= 7) pass7++;
            buy7 = dp[pass7] + costs[1];
            while (days[i] - days[pass30+1] >= 30) pass30++;
            buy30 = dp[pass30] + costs[2];
            
            dp[i] = min(buy1, min(buy7, buy30));
        }
        
        return dp.back();
    }
};
