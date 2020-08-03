class Solution {
public:
    int balancedStringSplit(string s) {
        stack<char> st;
        int res = 0;
        
        for (int i=0; i<s.size(); i++) {
            if (st.empty() || st.top() == s[i]) {
                st.push(s[i]);
            }
            else {
                st.pop();
                if (st.empty())
                    res++;
            }
        }
        
        return res;
    }
};
