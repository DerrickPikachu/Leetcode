class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<vector<int>> dp(A.size(), vector<int>(A.size(), 0));
        int res = 0;
        
        for (int i=0; i<A.size(); i++) {
            if (A[0] == B[i])
                dp[0][i] = 1;
            if (A[i] == B[0])
                dp[i][0] = 1;
        }
        
        for (int a=1; a<A.size(); a++) {
            for (int b=1; b<B.size(); b++) {
                if (A[a] == B[b])
                    dp[a][b] = dp[a-1][b-1] + 1;
                res = max(res, dp[a][b]);
            }
        }
        
        return res;
    }
};
