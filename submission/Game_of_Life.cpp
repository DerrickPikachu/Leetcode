class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        stack<pair<int, int>> st;
        vector<pair<int, int>> direct(8);
        
        direct[0] = pair<int, int>(-1, -1);
        direct[1] = pair<int, int>(-1, 0);
        direct[2] = pair<int, int>(-1, 1);
        direct[3] = pair<int, int>(0, -1);
        direct[4] = pair<int, int>(0, 1);
        direct[5] = pair<int, int>(1, -1);
        direct[6] = pair<int, int>(1, 0);
        direct[7] = pair<int, int>(1, 1);
        
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                int liveCount = 0;
                
                for (int d=0; d<8; d++) {
                    int r = i + direct[d].first, c = j + direct[d].second;
                    if (r < board.size() && r >= 0 && c < board[0].size() && c >= 0 
                        && board[r][c] == 1)
                        liveCount++;
                }
                
                if (board[i][j] == 1) {
                    if (liveCount < 2 || liveCount > 3)
                        st.push(pair<int, int>(i, j));
                }
                else {
                    if (liveCount == 3)
                        st.push(pair<int, int>(i, j));
                }
            }
        }
        
        while (!st.empty()) {
            pair<int, int> position = st.top();
            st.pop();
            board[position.first][position.second] = (board[position.first][position
                .second] == 1)? 0:1;
        }
    }
};
