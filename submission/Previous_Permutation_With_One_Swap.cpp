class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        for (int i=A.size()-2; i>=0; i--) {
            if (A[i] > A[i+1]) {
                int first = i + 1;
                
                for (int j=i+2; j<A.size() && A[j] < A[i]; j++) {
                    if (A[j] > A[first])
                        first = j;
                }
                
                swap(A[i], A[first]);
                break;
            }
        }
        
        return A;
    }
};
