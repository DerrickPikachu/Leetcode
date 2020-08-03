class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        vector<vector<double>> dp(K, vector<double>(A.size(), 0));
        double sum = 0;
        
        for (int i=0; i<A.size(); i++) {
            sum += A[i];
            dp[0][i] = sum / (i + 1);
            cout << dp[0][i] << endl;
        }
        
        for (int i=1; i<K; i++) {
            for (int j=i; j<A.size(); j++) {
                double sectionSum = 0;
                
                for (int k=j; k>=i; k--) {
                    sectionSum += A[k];
                    dp[i][j] = max(dp[i][j], dp[i-1][k-1] + sectionSum / (j - k + 1
                        ));
                }
            }
        }
        
        return dp.back().back();
    }
};
// 9 5 4 3.7 4.8
// 10 10.5 11 12.7
// 12 13.5 20

