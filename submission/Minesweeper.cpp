class Solution {
private:
    int search(vector<vector<char>>& board, pair<int, int>& point) {
        int row, col, count = 0;
        row = point.first;
        col = point.second;
        
        for (int i=-1; i<=1; i++) {
            for (int j=-1; j<=1; j++) {
                if ((i != 0 || j != 0) &&
                    row + i >= 0 &&
                    row + i < board.size() &&
                    col + j >= 0 &&
                    col + j < board[0].size()) {
                    if (board[row+i][col+j] == 'M')
                        count++;
                }
            }
        }
        
        return count;
    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) 
        {
        queue<pair<int, int>> que;
        pair<int, int> start(click[0], click[1]);
        int num;
        que.push(start);
        // cout << board.size() << " " << board[0].size() << endl;
        //first is row, second is column
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }//click is on the mine
        
        while (!que.empty()) {
            pair<int, int> step = que.front();
            int count;
            que.pop();
            
            if ((count = search(board, step)) == 0) {
                board[step.first][step.second] = 'B';
                for (int i=-1; i<=1; i++) {
                    for (int j=-1; j<=1; j++) {
                        if ((i != 0 || j != 0) &&
                            step.first + i >= 0 &&
                            step.first + i < board.size() &&
                            step.second + j >= 0 &&
                            step.second + j < board[0].size() &&
                            board[step.first+i][step.second+j] == 'E') {
                            board[step.first+i][step.second+j] = 'e';
                            pair<int, int> newStep(step.first+i, step.second+j);
                            que.push(newStep);
                        }
                    }
                }
            }
            else
                board[step.first][step.second] = count + '0';
        }
        
        return board;
    }
};
