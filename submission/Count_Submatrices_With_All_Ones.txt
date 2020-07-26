class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        vector<vector<int>> rowCount(mat.size(), vector<int>(mat[0].size()));
        int res = 0;
        
        for (int r = 0; r < mat.size(); r++) {
            for (int c = 0; c < mat[0].size(); c++) {
                if (mat[r][c]) {
                    rowCount[r][c] = (c != 0)? rowCount[r][c-1] + 1 : 1;
                    int mini = rowCount[r][c];
                    
                    for (int i = r; i >= 0; i--) {
                        if (mat[i][c] == 0)
                            break;
                        mini = min(mini, rowCount[i][c]);
                        res += mini;
                    }
                } else {
                    rowCount[r][c] = 0;
                }
            }
        }
        
        return res;
    }
};
