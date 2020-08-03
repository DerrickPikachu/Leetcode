class Solution {
private:
    vector<vector<int>> shift(vector<vector<int>>& grid) {
        vector<vector<int>> transfered(grid.size(), vector<int>(grid[0].size()));
        
        for (int r=0; r<grid.size(); r++) {
            for (int c=0; c<grid[0].size(); c++) {
                if (r == 0 && c == 0)
                    transfered[r][c] = grid.back().back();
                else if (c == 0)
                    transfered[r][c] = grid[r-1].back();
                else
                    transfered[r][c] = grid[r][c-1];
            }
        }
        
        return transfered;
    }
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        for (int i=0; i<k; i++)
            grid = shift(grid);
        
        return grid;
    }
};
