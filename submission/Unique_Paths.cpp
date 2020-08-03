class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n+1);
        for (int i=0; i<=m; i++)
            dp[0].push_back(0);
        for (int i=1; i<=n; i++)
            dp[i].push_back(0);
        for (int i=1; i<=m; i++)
            dp[1].push_back(1);
        
        for (int i=2; i<=n; i++) {
            for (int j=1; j<=m; j++)
                dp[i].push_back(dp[i][j-1] + dp[i-1][j]);
        }
        return dp[n][m];
    }
};
