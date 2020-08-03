class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int k) {
        vector<int> dp(A.size(), 0);
        
        dp[0] = A[0];
        for (int i=1; i<A.size(); i++) {
            int currmax = 0;
            for (int j=i, count = 1; j > i-k && j >= 0; j--, count++) {
                currmax = max(currmax, A[j]);
                int num = (j == 0)? currmax * count:dp[j-1] + currmax * count;
                dp[i] = max(dp[i], num);
            }
        }
        
        return dp.back();
    }
};
