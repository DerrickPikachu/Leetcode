class Solution {
private:
    vector<char> op = {'*', '/', '+', '-'};
    //0:* 1:/ 2:+ 3:-
    void calculate(stack<int>& numSt, stack<char>& opSt) {
        int res;
        int num1 = numSt.top();
        numSt.pop();
        int num2 = numSt.top();
        numSt.pop();
        char _op = opSt.top();
        opSt.pop();
        
        switch(_op) {
            case '*':
                res = num2 * num1;
                break;
            case '/':
                res = num2 / num1;
                break;
            case '+':
                res = num2 + num1;
                break;
            case '-':
                res = num2 - num1;
        }
        
        // cout << res << endl;
        numSt.push(res);
    }
public:
    int clumsy(int N) {
        int curNum = N - 1;
        stack<int> numSt;
        stack<char> opSt;
        unordered_map<char, int> priority;
        
        priority['+'] = 1;
        priority['-'] = 1;
        priority['*'] = 2;
        priority['/'] = 2;
        numSt.push(N);
        
        for (int i=0; curNum != 0; i++, curNum--) {
            
            if (opSt.empty() || priority[opSt.top()] < priority[op[i%4]]) {
                numSt.push(curNum);
                opSt.push(op[i%4]);
            }
            else {
                while(!opSt.empty() && priority[opSt.top()] >= priority[op[i%4]]) {
                    calculate(numSt, opSt);
                }
                numSt.push(curNum);
                opSt.push(op[i%4]);
            }
            // cout << op[i%4] << " " << curNum << endl;
        }
        
        while (!opSt.empty()) {
            calculate(numSt, opSt);
        }
        
        return numSt.top();
    }
};
