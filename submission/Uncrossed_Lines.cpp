class Solution {
public:
    int maxUncrossedLines(vector<int>& a, vector<int>& b) {
        vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));
        a.insert(a.begin(), 0);
        b.insert(b.begin(), 0);
        
        for (int r=1; r<a.size(); r++) {
            int num = a[r], maximum = 0;
            
            for (int c=1; c<b.size(); c++) {
                dp[r][c] = dp[r][c-1];
                if (num == b[c]) {
                    dp[r][c] = max(dp[r-1][c-1] + 1, dp[r][c-1]);
                }
                dp[r][c] = max(dp[r][c], dp[r-1][c]);
            }
        }
        
        return dp.back().back();
    }
};
