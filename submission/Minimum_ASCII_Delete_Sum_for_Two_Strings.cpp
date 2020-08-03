class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), 0));
        int sum1 = 0, sum2 = 0;
        dp[0][0] = (s1[0] == s2[0])? s1[0]:0;
        
        for (int i=0; i<s1.size(); i++)
            sum1 += s1[i];
        for (int i=0; i<s2.size(); i++)
            sum2 += s2[i];
        
        for (int i=1; i<s2.size(); i++)
            dp[0][i] = (s1[0] == s2[i])? s1[0]:dp[0][i-1];
        for (int i=1; i<s1.size(); i++)
            dp[i][0] = (s1[i] == s2[0])? s2[0]:dp[i-1][0];
        
        for (int i=1; i<s1.size(); i++) {
            for (int j=1; j<s2.size(); j++) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = max(dp[i-1][j-1] + s1[i], max(dp[i-1][j], dp[i][j-1]
                        ));
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return sum1 + sum2 - 2*dp[s1.size()-1][s2.size()-1];
    }

