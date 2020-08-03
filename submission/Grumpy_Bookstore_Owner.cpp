class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int res = 0, xSum = 0;
        vector<int> dp(customers.size());
        vector<int> usedX(customers.size());
        
        xSum = customers[0];
        dp[0] = (!grumpy[0])? customers[0]:0;
        res = max(xSum, dp[0]);
        usedX[0] = xSum;
        
        for (int i=1; i<customers.size(); i++) {
            if (!grumpy[i]) {
                dp[i] = dp[i-1] + customers[i];
                usedX[i] = usedX[i-1] + customers[i];
            }
            else {
                dp[i] = dp[i-1];
                usedX[i] = usedX[i-1];
            }
            
            if (X-1 >= i) {
                xSum += customers[i];
                usedX[i] = max(xSum, usedX[i]);
                res = max(res, max(dp[i], usedX[i]));
            }
            else {
                xSum += customers[i] - customers[i-X];
                usedX[i] = max(dp[i-X] + xSum, usedX[i]);
                res = max(res, max(dp[i], usedX[i]));
            }
        }
        
        return res;
    }
};
