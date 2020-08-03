class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int len = grid[0].size();
        vector<vector<int>> dp(grid.size());
        dp[0].push_back(grid[0][0]);
        
        for (int i=0; i<dp.size(); i++) {
            int j = (i == 0)? 1:0;
            for (; j<len; j++) {
                if (i == 0) dp[i].push_back(dp[i][j-1] + grid[i][j]);
                else if (j == 0) dp[i].push_back(dp[i-1][j] + grid[i][j]);
                else dp[i].push_back(min(dp[i-1][j], dp[i][j-1]) + grid[i][j]);
            }
        }
        
        return dp[dp.size()-1][len-1];
    }
};
