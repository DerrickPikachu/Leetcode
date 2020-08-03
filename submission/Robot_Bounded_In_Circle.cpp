class Solution {
private:
    class Robot {
    public:
        int x = 0, y = 0, toward = 0;
        
        void controlRobot(int vecX, int vecY, int rotate) {
            if (toward == 0) {
                x += vecX;
                y += vecY;
            }
            else if (toward == 3) {
                x += vecX;
                y -= vecY;
            }
            else if (toward == 2) {
                x -= vecX;
                y -= vecY;
            }
            else {
                x -= vecX;
                y += vecY;
            }
            
            if (rotate == 1)
                toward++;
            else if (rotate == 2)
                toward += 2;
            else if (rotate == 3) {
                toward--;
                if (toward < 0)
                    toward += 4;
            }
            toward %= 4;
        }
    };
public:
    bool isRobotBounded(string instructions) {
        int vecx = 0, vecy = 0, toward = 0, count = 0;
        Robot robot;
        
        for (int i = 0; i < instructions.size(); i++) {
            if (instructions[i] == 'G') {
                if (toward == 0)
                    vecy++;
                else if (toward == 3)
                    vecx++;
                else if (toward == 2)
                    vecy--;
                else if (toward == 1)
                    vecx--;
            }
            else if (instructions[i] == 'R') {
                toward--;
                if (toward < 0)
                    toward += 4;
            }
            else if (instructions[i] == 'L') {
                toward++;
                toward %= 4;
            }
        }
        
        while (count < 5000) {
            robot.controlRobot(vecx, vecy, toward);
            if (robot.x == 0 && robot.y == 0)
                return true;
            count++;
        }
        
        return false;
    }
};
