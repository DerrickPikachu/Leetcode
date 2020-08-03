class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool isIncrease;
        int i = 0;
        
        for (; i < A.size()-1 && A[i] == A[i+1]; i++) {}
        
        if (i != A.size()-1)
            isIncrease = (A[i] < A[i+1])? true:false;
        else
            return true;
        
        for (i++; i < A.size()-1; i++) {
            if (isIncrease && A[i] > A[i+1]) return false;
            else if (!isIncrease && A[i] < A[i+1]) return false;
        }
        
        return true;
    }
};
