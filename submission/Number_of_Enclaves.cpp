class Solution {
private:
    vector<pair<int, int>> direction;
    
    int dfs(vector<vector<int>>& m, int row, int col, bool& isBound, vector<vector
        <int>>& isArrive) {
        int count = 1;
        isArrive[row][col] = 1;
        
        for (int i=0; i<4; i++) {
            int r = row + direction[i].first, c = col + direction[i].second;
            
            //near the bound
            if (r < 0 || r >= m.size() || c < 0 || c >= m[0].size()) {
                isBound = true;
            }
            else if (!isArrive[r][c] && m[r][c] == 1) {
                //there is a next grid
                count += dfs(m, r, c, isBound, isArrive);
            }
        }
        
        return (isBound)? 0:count;
    }
public:
    Solution() {
        direction.push_back(pair<int, int>(-1, 0));
        direction.push_back(pair<int, int>(1, 0));
        direction.push_back(pair<int, int>(0, -1));
        direction.push_back(pair<int, int>(0, 1));
    }
    
    int numEnclaves(vector<vector<int>>& A) {
        int res = 0;
        bool isBound = false;
        vector<vector<int>> isArrive(A.size(), vector<int>(A[0].size(), 0));
        
        for (int i=1; i<A.size()-1; i++) {
            for (int j=1; j<A[0].size()-1; j++) {
                if (A[i][j] == 1 && !isArrive[i][j]) {
                    res += dfs(A, i, j, isBound, isArrive);
                    isBound = false;
                }
            }
        }
        
        return res;
    }
};
