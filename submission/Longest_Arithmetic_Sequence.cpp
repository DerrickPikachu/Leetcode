class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        unordered_map<int, unordered_map<int, int>> discreteDp;
        int res = 0;
        
        for (int i=1; i<A.size(); i++) {
            for (int j=i-1; j>=0; j--) {
                int diff = A[i] - A[j];
                if (discreteDp[diff].count(j))
                    discreteDp[diff][i] = max(discreteDp[diff][i], 
                        discreteDp[diff][j] + 1);
                else
                    discreteDp[diff][i] = max(discreteDp[diff][i], 2);
                res = max (res, discreteDp[diff][i]);
            }
        }
        
        return res;
    }
};
