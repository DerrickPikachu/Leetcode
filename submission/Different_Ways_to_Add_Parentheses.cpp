class Solution {
    bool isOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/');
    }
    
    int calculate(int num1, int num2, char op) {
        switch(op) {
            case '+':
                return num1 + num2;
            case '-':
                return num1 - num2;
            case '*':
                return num1 * num2;
            case '/':
                return num1 / num2;
        }
        return 0;
    }
    
    bool noOp(string operation) {
        for (int i=0; i<operation.size(); i++) {
            if (isOperator(operation[i]))
                return false;
        }
        
        return true;
    }
    
    int calOperation(vector<int>& num, vector<char>& op) {
        int res = num.back();
        
        for (int n=num.size() - 2, o=op.size() - 1; n>=0 && o >= 0; n--, o--)
            res = calculate(num[n], res, op[o]);
        
        return res;
    }
    
public:
    vector<int> diffWaysToCompute(string input) {
        if (noOp(input))
            return vector<int>(1, stoi(input));
        vector<int> res;
        
        for (int i=0; i<input.size(); i++) {
            if (isOperator(input[i])) {
                char op = input[i];
                vector<int> left = diffWaysToCompute(string(input.begin(), input
                    .begin() + i));
                vector<int> right = diffWaysToCompute(string(input.begin() + i + 1, 
                    input.end()));
                
                for (int l=0; l<left.size(); l++) {
                    for (int r=0; r<right.size(); r++) {
                        res.push_back(calculate(left[l], right[r], op));
                    }
                }
            }
        }
        
        return res;
    }
};
