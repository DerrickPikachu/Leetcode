class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<string> buffer;
        string res = "";
        
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '(') {
                string newTop = "";
                buffer.push(newTop);
            }
            else if (s[i] == ')') {
                if (!buffer.empty()) {
                    string top = buffer.top();
                    buffer.pop();

                    if (buffer.empty())
                        res = res + "(" + top + ")";
                    else {
                        string preTop = buffer.top();
                        buffer.pop();
                        preTop = preTop + "(" + top + ")";
                        buffer.push(preTop);
                    }
                }
            }
            else {
                //s[i] is an aphabet
                if (buffer.empty())
                    res.push_back(s[i]);
                else {
                    string top = buffer.top();
                    buffer.pop();
                    top.push_back(s[i]);
                    buffer.push(top);
                }
            }
        }
        
        while (buffer.size() > 1) {
            string top = buffer.top();
            buffer.pop();
            string preTop = buffer.top();
            buffer.pop();
            preTop = preTop + top;
            buffer.push(preTop);
        }
        
        if (!buffer.empty())
            res += buffer.top();
        return res;
    }
};
