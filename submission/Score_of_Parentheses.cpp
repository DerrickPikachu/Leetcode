class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<string> st;
        string tem;
        int res = 0;
        
        tem.push_back(s[0]);
        st.push(tem);
        
        for (int i=1; i<s.size(); i++) {
            if (s[i] == '(') {
                tem[0] = s[i];
                st.push(tem);
            }
            else if (s[i] == ')') {
                if (s[i-1] == '(') {
                    st.pop();
                    tem[0] = '1';
                    st.push(tem);
                }
                else {
                    int num = 0;
                    while (st.top() != "(") {
                        num += stoi(st.top());
                        st.pop();
                    }
                    st.pop();
                    st.push(to_string(num * 2));
                }
            }
        }
        
        while (!st.empty()) {
            res += stoi(st.top());
            st.pop();
        }
        
        return res;
    }
};
