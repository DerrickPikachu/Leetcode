class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        vector<vector<int>> res(mat.size(), vector<int>(mat[0].size(), 0));
        
        for (int r = 1; r < mat.size(); r++)
            mat[r][0] += mat[r-1][0];
        for (int c = 1; c < mat[0].size(); c++)
            mat[0][c] += mat[0][c-1];
        for (int r = 1; r < mat.size(); r++)
            for (int c = 1; c < mat[0].size(); c++)
                mat[r][c] += mat[r-1][c] + mat[r][c-1] - mat[r-1][c-1];
        
        for (int r = 0; r < res.size(); r++) {
            for (int c = 0; c < res[0].size(); c++) {
                int fromR = (r - K >= 0)? r - K : 0;
                int fromC = (c - K >= 0)? c - K : 0;
                int toR = (r + K < res.size())? r + K : res.size() - 1;
                int toC = (c + K < res[0].size())? c + K : res[0].size() - 1;
                
                res[r][c] = mat[toR][toC];
                if (fromR != 0)
                    res[r][c] -= mat[fromR-1][toC];
                if (fromC != 0)
                    res[r][c] -= mat[toR][fromC-1];
                if (fromR != 0 && fromC != 0)
                    res[r][c] += mat[fromR-1][fromC-1];
            }
        }
        
        return res;
    }
};
