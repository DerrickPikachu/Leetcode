class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int longLen = max(num1.size()-1, num2.size()-1), shortLen = min(num2.size()-1
            , num1.size()-1);
        int carry=0;
        string longStr=(num1.size() >= num2.size())? num1:num2;
        string shortStr=(num1.size() >= num2.size())? num2:num1;
        
        for (; longLen>=0 && shortLen>=0; longLen--, shortLen--) {
            int i=longStr[longLen] - '0';
            int j=shortStr[shortLen] - '0';
            int sum = i + j + carry;
            carry = sum/10;
            ans = to_string(sum % 10) + ans;
        }
        for (; longLen>=0; longLen--) {
            int sum = longStr[longLen] - '0' + carry;
            carry = sum / 10;
            ans = to_string(sum % 10) + ans;
        }
        if (carry != 0) {
            ans = to_string(carry) + ans;
        }
        
        return ans;
    }
};
