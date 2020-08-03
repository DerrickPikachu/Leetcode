class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int res = 0;
        
        for (int r=0; r<grid.size(); r++) {
            for (int c=0; c<grid[0].size(); c++) {
                if (grid[r][c]) {
                    grid[r][c] = 0;
                    queue<pair<int, int>> bfsRow, bfsCol;
                    bfsRow.push(pair<int, int>(r, c));
                    bfsCol.push(pair<int, int>(r, c));
                    int count = 0;
                    
                    while (!bfsRow.empty() || !bfsCol.empty()) {
                        while (!bfsRow.empty()) {
                            count++;
                            pair<int, int> pos = bfsRow.front();
                            bfsRow.pop();
                            
                            for (int i=0; i<grid[0].size(); i++) {
                                if (grid[pos.first][i]) {
                                    grid[pos.first][i] = 0;
                                    bfsCol.push(pair<int, int>(pos.first, i));
                                }
                            }
                        }
                        while (!bfsCol.empty()) {
                            count++;
                            pair<int, int> pos = bfsCol.front();
                            bfsCol.pop();
                            
                            for (int i=0; i<grid.size(); i++) {
                                if (grid[i][pos.second]) {
                                    grid[i][pos.second] = 0;
                                    bfsRow.push(pair<int, int>(i, pos.second));
                                }
                            }
                        }
                    }
                    
                    count--;
                    if (count != 1)
                        res += count;
                }
            }
        }
        
        return res;
    }
};
