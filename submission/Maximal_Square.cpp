class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int ans=0;
        vector<vector<int>> dp(matrix.size());
        for (int i=0; i<matrix.size(); i++)
            for (int j=0; j<matrix[0].size(); j++)
                if (matrix[i][j] == '1') {
                    dp[i].push_back(1);
                    ans = 1;
                }
                else
                    dp[i].push_back(0);
        for (int n=1; n<min(matrix.size(), matrix[0].size()); n++) {
            for (int i=matrix.size()-1; i>=n; i--) {
                for (int j=matrix[0].size()-1; j>=n; j--) {
                    if (dp[i-1][j-1] && dp[i-1][j] && dp[i][j-1] && matrix[i][j] == 
                        '1') {
                        dp[i][j] = 1;
                        ans = n + 1;
                    }
                    else dp[i][j] = 0;
                }
            }
        }
        
        return ans*ans;
    }
};
