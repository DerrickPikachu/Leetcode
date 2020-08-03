class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i;
        
        for (i=0;i<s.size();i++) {
            if (st.size() != 0 && s.at(i) == ')' && st.top() == '(')
                st.pop();
            else if (st.size() != 0 && s.at(i) == ']' && st.top() == '[')
                st.pop();
            else if (st.size() != 0 && s.at(i) == '}' && st.top() == '{')
                st.pop();
            else
                st.push(s.at(i));
        }
        
        return st.empty();
    }
};
