class Solution {
public:
    void StackNewString(stack<char>& st, string& str) {
        int i=0;
        while(str[i] == '#')    i++;
        for (i; i<str.size(); i++) {
            if (str[i] != '#')
                st.push(str[i]);
            else if(!st.empty())
                st.pop();
        }
    }
    string deStack(stack<char>& st) {
        string str;
        while (!st.empty()) {
            str.push_back(st.top());
            st.pop();
        }
        return str;
    }
    bool backspaceCompare(string S, string T) {
        stack<char> new_s,new_t;
        
        StackNewString(new_s, S);
        StackNewString(new_t, T);
        S = deStack(new_s);
        T = deStack(new_t);
        
        cout << S << endl;
        cout << T << endl;
        return (S == T)? true:false;
    }
};
