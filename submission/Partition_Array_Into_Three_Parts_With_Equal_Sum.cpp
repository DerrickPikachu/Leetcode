class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        vector<int> accumulate(A.size());
        unordered_set<int> st;
        int sum = 0;
        
        accumulate[0] = A[0];
        for (int i=1; i<A.size(); i++)
            accumulate[i] = A[i] + accumulate[i-1];
        
        st.insert(A[0]);
        for (int i=1; i<A.size(); i++) {
            if (accumulate[i] % 2 == 0) {
                int divide = accumulate[i] >> 1;
                
                if (st.count(divide) && divide == accumulate.back() - accumulate[i])
                    return true;
            }
            
            st.insert(accumulate[i]);
        }
        
        return false;
    }
};
