class Solution {
private:
    vector<vector<int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    bool checkValid(int r, int c, vector<vector<int>>& grid) {
        return r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size();
    }
    
    void DFS(int& res, int r, int c, vector<vector<int>>& grid, int count = 0) {
        count += grid[r][c];
        int save = grid[r][c];
        grid[r][c] = 0;
        
        for (int i=0; i<direction.size(); i++) {
            int _r = r + direction[i][0], _c = c + direction[i][1];
            
            if (checkValid(_r, _c, grid) && grid[_r][_c] != 0) {
                DFS(res, _r, _c, grid, count);
            }
        }
        
        grid[r][c] = save;
        res = max(count, res);
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int res = 0;
        
        for (int r=0; r<grid.size(); r++) {
            for (int c=0; c<grid[0].size(); c++) {
                if (grid[r][c] != 0) {
                    vector<vector<int>> _grid = grid;
                    DFS(res, r, c, _grid);
                }
            }
        }
        
        return res;
    }
};
