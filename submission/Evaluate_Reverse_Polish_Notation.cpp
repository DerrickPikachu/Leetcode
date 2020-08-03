class Solution {
public:
    int evalRPN(vector<string>& tokens) {
         stack<int> sta;
        
        for (int i=0; i<tokens.size(); i++) {
            int element, a, b;
            if (tokens[i] == "+") {
                a = sta.top();
                sta.pop();
                b = sta.top();
                sta.pop();
                element = a + b;
            }
            else if (tokens[i] == "-") {
                a = sta.top();
                sta.pop();
                b = sta.top();
                sta.pop();
                element = b - a;
            }
            else if (tokens[i] == "*") {
                a = sta.top();
                sta.pop();
                b = sta.top();
                sta.pop();
                element = a * b;
            }
            else if (tokens[i] == "/") {
                a = sta.top();
                sta.pop();
                b = sta.top();
                sta.pop();
                element = b / a;
            }
            else
                element = stoi(tokens[i]);
            sta.push(element);
        }
        
        return sta.top();
    }
};
