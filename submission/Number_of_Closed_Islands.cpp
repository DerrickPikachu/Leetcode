class Solution {
private:
    vector<vector<int>> direct = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    int dfs(vector<vector<int>>& grid, int r, int c, int valid = 1) {
        if (r == 0 || r == grid.size() - 1 || c == 0 || c == grid[0].size() - 1)
            valid = 0;
        grid[r][c] = 1;
        
        for (int i=0; i<4; i++) {
            int nextR = r + direct[i][0], nextC = c + direct[i][1];
            
            if (nextR >= 0 && nextR < grid.size() && nextC >= 0 && nextC < grid[0]
                .size()) {
                if (!grid[nextR][nextC])
                    valid = dfs(grid, nextR, nextC, valid);
            }
        }
        
        return valid;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int res = 0;
        
        for (int r=0; r<grid.size(); r++) {
            for (int c=0; c<grid[0].size(); c++) {
                if (!grid[r][c]) {
                    res += dfs(grid, r, c);
                }
            }
        }
        
        return res;
    }
};
