class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int res = 0;
        
        for (int x : {-1, 1}) {
            for (int y : {-1, 1}) {
                int maxVal, minVal;
                maxVal = minVal = x * arr1[0] + y * arr2[0] + 0;
                
                for (int i = 1; i < arr1.size(); i++) {
                    int cur = x * arr1[i] + y * arr2[i] + i;
                    maxVal = max(maxVal, cur);
                    minVal = min(minVal, cur);
                }
                
                res = max(res, maxVal - minVal);
            }
        }
        
        return res;
    }
};
