class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        int length = 1, res = 1;
        
        for (int i=0; i<s.size(); i++) {
            dp[i][i] = 1;
        }
        
        while (length < s.size()) {
            for (int i=0; i + length < s.size(); i++) {
                int j = i + length, previous = max(dp[i][j-1], dp[i+1][j]);
                
                if (s[i] == s[j])
                    dp[i][j] = max(previous, dp[i+1][j-1] + 2);
                else
                    dp[i][j] = previous;
                
                res = max(res, dp[i][j]);
            }
            
            length++;
        }
        
        return res;
    }
};
