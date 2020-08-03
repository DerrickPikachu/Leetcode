class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) return 0;
        int zero=0, now_dif;
        vector<int> DP(A.size());
        DP[0] = 0, DP[1] = 0;
        now_dif = A[1] - A[0];
        
        for (int i=2; i<A.size(); i++) {
            int dif = A[i] - A[i-1];
            if (dif == now_dif) {
                int size = i - zero + 1;
                DP[i] = (size >= 3)? size - 2 + DP[i-1]:DP[i-1];
            }
            else {
                zero = i-1;
                now_dif = dif;
                DP[i] = DP[i-1];
            }
        }
        
        return DP[DP.size()-1];
    }
};
