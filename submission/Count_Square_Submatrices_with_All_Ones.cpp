class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>> rCount(matrix.size(), vector<int>(matrix[0].size()));
        vector<vector<int>> cCount(matrix.size(), vector<int>(matrix[0].size()));
        vector<vector<int>> mCount(matrix.size(), vector<int>(matrix[0].size()));
        int res = 0;
        
        // Initialize
        for (int c=0; c<matrix[0].size(); c++) {
            res += matrix[0][c];
            cCount[0][c] = matrix[0][c];
            mCount[0][c] = matrix[0][c];
        }
        for (int r=0; r<matrix.size(); r++) {
            res += matrix[r][0];
            rCount[r][0] = matrix[r][0];
            mCount[r][0] = matrix[r][0];
        }
        if (matrix[0][0] == 1)  res--;
        
        // cout << res << endl;
        
        for (int r=1; r<matrix.size(); r++) {
            for (int c=1; c<matrix[0].size(); c++) {
                if (matrix[r][c] == 1) {
                    int possible = min(cCount[r-1][c], min(rCount[r][c-1], mCount[r
                        -1][c-1]));
                    // cout << "possible:" << possible << endl;
                    // cout << "count:" << cCount[r-1][c] << " " << rCount[r][c-1] << 
                        " " << mCount[r-1][c-1] << endl;
                    res += possible + 1;
                    cCount[r][c] = cCount[r-1][c] + 1;
                    rCount[r][c] = rCount[r][c-1] + 1;
                    mCount[r][c] = possible + 1;
                    // cout << r << " " << c << " " << res << endl;
                }
                else {
                    cCount[r][c] = 0;
                    rCount[r][c] = 0;
                    mCount[r][c] = 0;
                }
            }
        }
        
        return res;
    }
};
// [
//     [1,1,0,0,1],
//     [1,0,1,1,1],
//     [1,1,1,1,1],
//     [1,0,1,0,1],
//     [0,0,1,0,1]
// ]
