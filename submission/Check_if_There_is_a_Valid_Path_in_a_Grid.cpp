class Solution {
private:
    vector<vector<int>> type;
    vector<unordered_set<int>> directs;
    
    bool dfs(int posx, int posy, vector<vector<int>>& grid, vector<vector<int>>& 
        arrived) {
        int streetType = grid[posx][posy];
        if (posx == grid.size() - 1 && posy == grid[0].size() - 1)
            return true;
        
        for (int& direct : type[streetType]) {
            int nextx, nexty;
            
            if (direct == 0) {
                nextx = posx - 1;
                nexty = posy;
            } else if (direct == 1) {
                nextx = posx;
                nexty = posy + 1;
            } else if (direct == 2) {
                nextx = posx + 1;
                nexty = posy;
            } else {
                nextx = posx;
                nexty = posy - 1;
            }
            
            if (nextx >= 0 && nextx < grid.size() && nexty >= 0 && nexty < grid[0]
                .size()) {
                // cout << nextx << " " << nexty << endl;
                
                if (!arrived[nextx][nexty] && directs[direct].count
                    (grid[nextx][nexty])) {
                    arrived[nextx][nexty] = 1;
                    if (dfs(nextx, nexty, grid, arrived))
                        return true;
                }
            }
        }
        
        return false;
        
    }
public:
    Solution() {
        type.resize(7);
        directs.resize(4);
        type[1] = {3, 1};
        type[2] = {0, 2};
        type[3] = {3, 2};
        type[4] = {1, 2};
        type[5] = {0, 3};
        type[6] = {0, 1};
        directs[0].insert(2);
        directs[0].insert(3);
        directs[0].insert(4);
        directs[1].insert(1);
        directs[1].insert(3);
        directs[1].insert(5);
        directs[2].insert(2);
        directs[2].insert(5);
        directs[2].insert(6);
        directs[3].insert(1);
        directs[3].insert(4);
        directs[3].insert(6);
    }
    
    bool hasValidPath(vector<vector<int>>& grid) {
        vector<vector<int>> arrived(grid.size(), vector<int>(grid[0].size(), 0));
        return dfs(0, 0, grid, arrived);
    }
};
