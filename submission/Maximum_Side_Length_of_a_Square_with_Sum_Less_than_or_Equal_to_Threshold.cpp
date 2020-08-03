class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        vector<vector<int>> dp(mat.size(), vector<int>(mat[0].size(), 0));
        int res = 0;
        
        for (int i=0; i<mat.size(); i++) {
            if (mat[i][0] <= threshold) {
                res = 1;
                dp[i][0] = 1;
                if (i > 0)
                    mat[i][0] += mat[i-1][0];
            }
        }
        for (int i=0; i<mat[0].size(); i++) {
            if (mat[0][i] <= threshold) {
                res = 1;
                dp[0][i] = 1;
                if (i > 0)
                    mat[0][i] += mat[0][i-1];
            }
        }
        
        for (int r=1; r<mat.size(); r++) {
            for (int c=1; c<mat[0].size(); c++) {
                int leng = min(dp[r-1][c-1], min(dp[r-1][c], dp[r][c-1])) + 1;
                int sumFromRow, sumFromCol, sumFromMatrix, acceptable = INT_MAX;
                mat[r][c] = mat[r][c-1] + mat[r-1][c] - mat[r-1][c-1] + mat[r][c];
                
                while (acceptable > threshold && leng > 0) {
                    sumFromRow = (c - leng < 0)? 0:mat[r][c-leng];
                    sumFromCol = (r - leng < 0)? 0:mat[r-leng][c];
                    sumFromMatrix = (r - leng < 0 || c - leng < 0)? 0:mat[r-leng][c
                        -leng];
                    acceptable = mat[r][c] - (sumFromRow + sumFromCol - sumFromMatrix
                        );
                    leng--;
                }
                
                if (acceptable > threshold && leng == 0)
                    dp[r][c] = leng;
                else
                    dp[r][c] = leng + 1;
                
                res = max(res, dp[r][c]);
            }
        }
        
        return res;
    }
};
