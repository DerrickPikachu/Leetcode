class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int ans = INT_MIN;
        vector<int> dp(pairs.size(), 0);
        for (int i=1; i<pairs.size(); i++) {
            for (int j=i; j>0 && pairs[j][0] < pairs[j-1][0]; j--)
                swap(pairs[j], pairs[j-1]);
        }//insertion sort
        
        dp[0] = 1;
        for (int i=1; i<dp.size(); i++) {
            int maximum = 1;
            for (int j=i-1; j>=0; j--) {
                if (pairs[j][1] < pairs[i][0]) {
                    maximum = max(maximum, dp[j] + 1);
                }
            }
            dp[i] = maximum;
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};
