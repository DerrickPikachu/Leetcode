class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(3);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for (int i=3; i<=n; i++)
            dp.push_back(dp[i-1] + dp[i-2]);
        return dp[n];
    }
};
