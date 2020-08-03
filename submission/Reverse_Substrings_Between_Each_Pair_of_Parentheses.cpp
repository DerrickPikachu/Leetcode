class Solution {
public:
    string reverseParentheses(string s) {
        string tem = "";
        stack<string> st;
        
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '(') {
                st.push(tem);
                tem = "";
            }
            else if (s[i] == ')') {
                string top = st.top();
                st.pop();
                reverse(tem.begin(), tem.end());
                tem = top + tem;
            }
            else
                tem.push_back(s[i]);
        }
        
        if (!st.empty()) {
            string top = st.top();
            tem = top + tem;
        }
        
        return tem;
    }
};
