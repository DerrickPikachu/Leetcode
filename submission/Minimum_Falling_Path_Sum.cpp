class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        vector<vector<int>> dp(A.size());
        
        for (int i=0; i<A[0].size(); i++)
            dp[0].push_back(A[0][i]);
        
        for (int i=1; i<A.size(); i++) {
            for (int j=0; j<A[0].size(); j++) {
                int minimum;
                
                if (j == 0)
                    minimum = min(dp[i-1][j], dp[i-1][j+1]);
                else if (j == A[0].size()-1)
                    minimum = min(dp[i-1][j-1], dp[i-1][j]);
                else
                    minimum = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i-1][j+1]);
                
                dp[i].push_back(A[i][j] + minimum);
            }
        }
        
        int ans = INT_MAX;
        for (int i=0; i<dp.back().size(); i++)
            ans = (ans > dp.back()[i])? dp.back()[i]:ans;
        
        
        return ans;
    }
};
