class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len,i;
        len = digits.size();
        digits[len-1]++;
        
        for (i=len-1;i>0;i--) {
            digits[i-1] += digits[i]/10;
            digits[i] = digits[i]%10;
        }
        if (digits[0]/10 != 0) {
            digits.push_back(digits[len-1]);
            for (i=len-1;i>0;i--) 
                digits[i] = digits[i-1];
            digits[1] = digits[0]%10;
            digits[0] = digits[0]/10;
        }
        return digits;
    }
};
