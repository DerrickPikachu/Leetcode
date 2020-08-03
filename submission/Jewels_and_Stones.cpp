class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> st;
        int ans = 0;
        
        for (int i=0; i<J.size(); i++)
            st.insert(J[i]);
        
        for (int i=0; i<S.size(); i++) {
            if (st.count(S[i]))
                ans++;
        }
        
        return ans;
    }
};
