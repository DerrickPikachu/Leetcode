class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        const int modulo = 1000000007;
        vector<vector<long int>> dp(7, vector<long int>(n, 1));
        vector<long int> possibleSum(7, 1);
        long int sum = 6;
        
        rollMax.insert(rollMax.begin(), 0);
        
        for (int i=1; i<n; i++) {
            long int nextSum = (sum * 6) % modulo;
            vector<long int> nextSumArr(7, 0);
            
            for (int j=1; j<=6; j++) {
                long int entrySum = 0;
                
                for (int c=1; c<=6; c++) {
                    if (c != j)
                        entrySum = (entrySum + possibleSum[c]) % modulo;
                }

                dp[j][i] = entrySum;
                cout << i << " " << j << endl;
                if (i - rollMax[j] >= 0) {
                    nextSum -= dp[j][i-rollMax[j]];
                    nextSumArr[j] = sum - dp[j][i-rollMax[j]];
                }
                else
                    nextSumArr[j] = sum % modulo;
            }
            
            possibleSum = nextSumArr;
            sum = nextSum % modulo;
        }
        
        return (sum < 0)? sum + modulo:sum;
    }
};
// 2
// [1,1,2,2,2,3]
// 3
// [1,1,2,2,2,3]
// 4
// [1,1,2,2,2,3]
// 2
// [1,1,1,1,1,1]
// 3
// [1,1,1,2,2,3]
// 10
// [2,7,1,2,6,5]
// 20
// [8,5,10,8,7,2]
