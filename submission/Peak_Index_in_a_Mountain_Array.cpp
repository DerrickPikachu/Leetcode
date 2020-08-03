class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int maximum = INT_MIN, maxIndex = 0;
        
        for (int i=0; i<A.size(); i++) {
            if (maximum < A[i]) {
                maximum = A[i];
                maxIndex = i;
            }
        }
        
        return maxIndex;
    }
};
