class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.empty() || B.empty() || (A.size() != B.size()))  return false;
        int diff=-1;
        bool repeat=false;
        unordered_set<char> st;
        
        for (int i=0; i<A.size(); i++) {
            if (A[i] != B[i]) {
                if (diff == -1)
                    diff = i;
                else if (diff == -2)
                    return false;
                else {
                    swap(A[diff], A[i]);
                    if (A == B) 
                        diff = -2;
                    else return false;
                }
            }
            if (st.find(A[i]) == st.end())
                st.insert(A[i]);
            else
                repeat = true;
        }
        return repeat? true:false;
    }
};
