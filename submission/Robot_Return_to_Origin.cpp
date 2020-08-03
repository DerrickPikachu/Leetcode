class Solution {
public:
    bool judgeCircle(string moves) {
        int i,x=0,y=0;
        
        for (i=0;i<moves.size();i++) {
            if (moves[i] == 'U')
                y++;
            else if (moves[i] == 'D')
                y--;
            else if (moves[i] == 'R')
                x++;
            else
                x--;
        }
        
        return (x == 0 && y == 0)? true:false;
    }
};
