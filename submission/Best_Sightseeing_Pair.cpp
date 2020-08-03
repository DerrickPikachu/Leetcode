class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int maximum = A[0], res = INT_MIN;
        
        
        for (int i=1; i<A.size(); i++) {
            
            res = max(res, --maximum + A[i]);
            
            if (maximum < A[i]) {
                maximum = A[i];
            }
        }
        
        return res;
    }
};
