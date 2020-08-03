class Solution {
private:
    void generateParenthesisHelper(int n, string paranthesis, int leftCount, int 
        rightCount, vector<string>& res) {
        if (rightCount < leftCount) {
            if (leftCount < n) {
                //two possible
                generateParenthesisHelper(n, paranthesis + "(", leftCount + 1, 
                    rightCount, res);
                generateParenthesisHelper(n, paranthesis + ")", leftCount, rightCount 
                    + 1, res);
            }
            else if (leftCount == n){
                //only ')'
                generateParenthesisHelper(n, paranthesis + ")", leftCount, rightCount 
                    + 1, res);
            }
        }
        else if (rightCount == leftCount) {
            if (leftCount < n) {
                //only '('
                generateParenthesisHelper(n, paranthesis + "(", leftCount + 1, 
                    rightCount, res);
            }
            else if (leftCount == n) {
                //leave recurrence
                res.push_back(paranthesis);
            }
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParenthesisHelper(n, "", 0, 0, res);
        return res;
    }
};
