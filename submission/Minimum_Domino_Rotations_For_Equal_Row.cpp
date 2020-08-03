class Solution {
private:
    int helper(vector<int>& A, vector<int>& B) {
        pair<int, int> possibleRes(A[0], B[0]), res(0, 1);
        
        for (int i=1; i<A.size(); i++) {
            if (possibleRes.first != INT_MAX) {
                if (B[i] == possibleRes.first && A[i] != possibleRes.first)
                    res.first++;
                else if (A[i] != possibleRes.first && B[i] != possibleRes.first) {
                    possibleRes.first = INT_MAX;
                    res.first = INT_MAX;
                }
            }
            
            if (possibleRes.second != INT_MAX) {
                if (B[i] == possibleRes.second && A[i] != possibleRes.second)
                    res.second++;
                else if (A[i] != possibleRes.second && B[i] != possibleRes.second) {
                    possibleRes.second = INT_MAX;
                    res.second = INT_MAX;
                }
            }
            
            if (possibleRes.first == INT_MAX && possibleRes.second == INT_MAX)
                return -1;
        }
        
        return min(res.first, res.second);
    }
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int res = helper(A, B);
        res = min(res, helper(B, A));
        return res;
    }
};
