class Solution {
private:
    vector<int> vir;
    vector<int> hor;
    
    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& 
        isArrive) {
        int maxRow = grid.size() - 1, maxCol = grid[0].size() - 1, res = 0;
        isArrive[row][col] = 1;
        
        for (int i=0; i<4; i++) {
            int r = row + vir[i], c = col + hor[i];
            
            if (r < 0 || r > maxRow || c < 0 || c > maxCol || grid[r][c] == 0)
                res++;
            else if (!isArrive[r][c])
                res += dfs(r, c, grid, isArrive);
        }
        
        return res;
    }
public:
    Solution() {
        vir.resize(4);
        hor.resize(4);
        vir[0] = -1;
        vir[1] = 1;
        vir[2] = 0;
        vir[3] = 0;
        hor[0] = 0;
        hor[1] = 0;
        hor[2] = -1;
        hor[3] = 1;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int res;
        bool isFind = false;
        vector<vector<int>> isArrive(grid.size(), vector<int>(grid[0].size(), 0));
        
        for (int i=0; i<grid.size() && !isFind; i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    res = dfs(i, j, grid, isArrive);
                    isFind = true;
                    break;
                }
            }
        }
        
        return res;
    }
};
