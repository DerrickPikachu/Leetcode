class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> row(grid.size()), col(grid.size(), 0);
        int size = grid.size(), res = 0;
        
        for (int r=0; r<size; r++) {
            int skyline = 0;
            
            for (int c=0; c<size; c++) {
                skyline = max(skyline, grid[r][c]);
                col[c] = max(col[c], grid[r][c]);
            }
            
            row[r] = skyline;
        }
        
        for (int r=0; r<size; r++) {
            for (int c=0; c<size; c++) {
                res += min(row[r], col[c]) - grid[r][c];
            }
        }
        
        return res;
    }
};
