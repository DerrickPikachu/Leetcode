class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        
        for (int& num : nums) {
            bool valid = false;
            int sqr = (int)sqrt(num);
            int target;
            
            if (sqr * sqr == num)
                continue;
            
            for (; sqr > 1; sqr--) {
                if (num % sqr == 0) {
                    valid = !valid;
                    if (!valid)
                        break;
                    else
                        target = sqr;
                }
            }
            if (valid)
                sum += 1 + num + target + (num / target);
        }
        
        return sum;
    }
};
