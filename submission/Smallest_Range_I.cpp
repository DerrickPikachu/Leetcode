class Solution {
public:
    int smallestRangeI(vector<int>& A, int k) {
        if (A.size() < 2) return 0;
        int minimum = INT_MAX, maximum = INT_MIN;
        
        for (int i=0; i<A.size(); i++) {
            maximum = (maximum < A[i])? A[i]:maximum;
            minimum = (minimum > A[i])? A[i]:minimum;
        }
        int diff = maximum - minimum;
        
        return (diff < 2 * k)? 0:diff - 2 * k;
    }
};
