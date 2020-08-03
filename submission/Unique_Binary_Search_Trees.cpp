class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        
        for (int i=1; i<=n; i++) {
            int tem=0;
            for (int j=0, k=i-1; j<=k; j++,k--)
                tem += (j == k)? dp[k]*dp[j]:2*dp[k]*dp[j];
            dp[i] = tem;
        }
        
        return dp[n];
    }
};
