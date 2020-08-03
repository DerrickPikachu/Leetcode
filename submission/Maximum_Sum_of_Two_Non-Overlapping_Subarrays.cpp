class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        vector<int> Larray(A.size());
        vector<int> Marray(A.size());
        vector<int> Ldp(A.size());
        vector<int> Mdp(A.size());
        int Lsum = 0, Msum = 0, res = 0;
        
        for (int i=0; i<A.size(); i++) {
            
            if (i >= L - 1) {
                if (i - L < 0)
                    Lsum += A[i];
                else
                    Lsum += A[i] - A[i - L];
                Larray[i] = Lsum;
            }
            else {
                Larray[i] = 0;
                Lsum += A[i];
            }
            
            if (i >= M - 1) {
                if (i - M < 0)
                    Msum += A[i];
                else
                    Msum += A[i] - A[i - M];
                Marray[i] = Msum;
            }
            else {
                Marray[i] = 0;
                Msum += A[i];
            }
            
        }
        
        Lsum = 0;
        Msum = 0;
        
        for (int i=0; i<A.size(); i++) {
            Lsum = max(Lsum, Larray[i]);
            Msum = max(Msum, Marray[i]);
            Ldp[i] = Lsum;
            Mdp[i] = Msum;
            
            if (i >= L + M - 1) {
                res = max(res, Larray[i] + Mdp[i - L]);
                res = max(res, Marray[i] + Ldp[i - M]);
            }
        }
        
        return res;
    }
};
