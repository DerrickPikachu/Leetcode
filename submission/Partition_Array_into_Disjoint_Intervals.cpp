class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int maxi = A[0], length = 1, nonPushMax = 0;
        
        for (int i=1; i<A.size(); i++) {
            if (A[i] < maxi) {
                length = i + 1;
                
                if (nonPushMax != 0) {
                    maxi = nonPushMax;
                    nonPushMax = 0;
                }
            }
            else
                nonPushMax = max(nonPushMax, A[i]);
        }
        
        return length;
    }
};
