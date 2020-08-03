class Solution {
private:
    int DFS(vector<vector<int>>& map,int r,int c) {
        static int x[4]={0,1,0,-1},y[4]={-1,0,1,0};
        int i,area=1,n_r,n_c;
        
        map[r][c] = 0;
        for (i=0;i<4;i++) {
            n_r = r + y[i];
            n_c = c + x[i];
            if (n_r < 0 || n_c < 0 || n_r >= map.size() || n_c >= map[0].size())
                continue;
            else if (map[n_r][n_c] == 1) {
                area += DFS(map,n_r,n_c);
            }
        }
        
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty())   return 0;
        int i,j,max=0,save;
        
        for (i=0;i<grid.size();i++) {
            for (j=0;j<grid[0].size();j++) {
                if (grid[i][j] == 1) {
                    save = DFS(grid,i,j);
                    if (max < save)
                        max = save;
                }
            }
        }
        
        return max;
    }
};
