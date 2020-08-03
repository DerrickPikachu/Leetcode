class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), INT_MAX));
        vector<vector<int>> maxleaf(arr.size(), vector<int>(arr.size(), 0));
        
        //initialize base case
        for (int i=0; i<arr.size(); i++) {
            dp[i][i] = 0;
            maxleaf[i][i] = arr[i];
        }
        
        for (int nodes = 2; nodes<=arr.size(); nodes++) {
            for (int i=0; i<=arr.size() - nodes; i++) {
                int j = i + nodes - 1;//j is the end of this interval
                
                for (int k=i; k<j; k++) {
                    int sum;
                    
                    sum = maxleaf[i][k] * maxleaf[k+1][j] + dp[i][k] + dp[k+1][j];
                    if (dp[i][j] > sum) {
                        maxleaf[i][j] = max(maxleaf[i][k], maxleaf[k+1][j]);
                        dp[i][j] = sum;
                    }
                }
            }
        }
        
        return dp[0].back();
    }
};
