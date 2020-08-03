class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        float slope;
        bool isZero = false;
        
        if (coordinates[1][0] != coordinates[0][0])
            slope = (float)(coordinates[1][1] - coordinates[0][1]) / (float
                )(coordinates[1][0] - coordinates[0][0]);
        else
            isZero = true;
        
        for (int i=2; i<coordinates.size(); i++) {
            if (!isZero) {
                float curSlope = (float)(coordinates[i][1] - coordinates[i-1][1]) / 
                    (float)(coordinates[i][0] - coordinates[i-1][0]);
                if (curSlope != slope)
                    return false;
            }
            else if (coordinates[i][0] != coordinates[i-1][0]){
                return false;
            }
        }
        
        return true;
    }
};
