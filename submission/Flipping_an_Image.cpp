class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (int i=0; i<A.size(); i++) {
            vector<int> tem(A[i].rbegin(), A[i].rend());
            for (int j=0; j<tem.size(); j++)
                tem[j] = tem[j]? 0:1;
            A[i] = tem;
        }
        
        return A;
    }
};
