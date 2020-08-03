class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<string> grid(3, string(3, ' '));
        vector<int> last = moves.back();
        bool hasWinner = false;
        
        for (int i=0; i<moves.size(); i++) {
            if (i % 2 == 0)
                grid[moves[i][0]][moves[i][1]] = 'X';
            else 
                grid[moves[i][0]][moves[i][1]] = 'O';
        }
        
        if (grid[last[0]][0] == grid[last[0]][1] && grid[last[0]][1] == 
            grid[last[0]][2])
            hasWinner = true;
        else if (grid[0][last[1]] == grid[1][last[1]] && grid[1][last[1]] == 
            grid[2][last[1]])
            hasWinner = true;
        else if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] !
            = ' ')
            hasWinner = true;
        else if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] !
            = ' ')
            hasWinner = true;
        
        if (hasWinner)
            return (moves.size() % 2 == 1)? "A":"B";
        else {
            if (moves.size() == 9)
                return "Draw";
            else
                return "Pending";
        }
    }
};
