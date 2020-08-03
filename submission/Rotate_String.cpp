class Solution {
public:
    bool rotateString(string A, string B) {
        if (A == "" && B == "")
            return true;
        
        for (int i=0; i<A.size(); i++) {
            if (A == B)
                return true;
            else {
                A.push_back(A[0]);
                A.erase(0, 1);
            }
        }
        
        return false;
    }
};
