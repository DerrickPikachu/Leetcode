class Solution {
public:
    bool divisorGame(int N) {
        vector<bool> dp(N+1);
        dp[0] = false;
        dp[1] = false;
        
        for (int i=2; i<=N; i++) {
            for (int j=2; j <= i; j++) {
                if (i % j == 0) {
                    int divisor = i / j;
                    dp[i] = !dp[i - divisor];
                }
            }
        }
        
        return dp[N];
    }
};
