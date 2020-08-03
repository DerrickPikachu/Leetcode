class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& 
        king) {
        vector<vector<int>> queensMap(8, vector<int>(8, 0)), res;
        vector<vector<int>> direct = {{-1,-1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, 
            -1}, {1, 0}, {1, 1}};
        int validDirect = 8;
        
        for (int i=0; i<queens.size(); i++) {
            int r = queens[i][0], c = queens[i][1];
            queensMap[r][c] = 1;
        }
        
        for (int count=1; validDirect; count++) {
            for (int i=0; i<8; i++) {
                int r = king[0] + count * direct[i][0], c = king[1] + count * 
                    direct[i][1];
                
                // cout << r << " " << c << endl;
                if (r >= 0 && r < 8 && c >= 0 && c < 8) {
                    if (queensMap[r][c]) {
                        cout << "fdsafd" << endl;
                        vector<int> tem;
                        tem.push_back(r);
                        tem.push_back(c);
                        
                        res.push_back(tem);
                        validDirect--;
                        direct[i][0] = 0;
                        direct[i][1] = 0;
                    }
                }
                else {
                    validDirect--;
                    direct[i][0] = 0;
                    direct[i][1] = 0;
                }
            }
        }
        
        return res;
    }
};
