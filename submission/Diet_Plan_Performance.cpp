class Solution {
private:
    int getPoint(int T, int lower, int upper) {
        if (T > upper)
            return 1;
        if (T < lower)
            return -1;
        return 0;
    }
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int T = 0, point = 0;
        
        for (int i=0; i<k; i++)
            T += calories[i];
        point += getPoint(T, lower, upper);
        
        for (int i=k; i<calories.size(); i++) {
            int newPos = i, oldPos = i - k;
            
            T += calories[newPos] - calories[oldPos];
            point += getPoint(T, lower, upper);
            
            cout << "T:" << T << endl;
            cout << "point:" << point << endl;
        }
        
        return point;
    }
};
