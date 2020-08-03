class Solution {
public:
    vector<int> closestDivisors(int num) {
        vector<int> res;
        int dist, num1 = num + 1, num2 = num + 2;
        
        for (int i = sqrt(num1); i >= 1; i--) {
            if (num1 % i == 0) {
                dist = num1 / i - i;
                res = {i, num1 / i};
                break;
            }
        }
        for (int i = sqrt(num2); i >= 1; i--) {
            if (num2 % i == 0) {
                if (dist > num2 / i - i)
                    res = {i, num2 / i};
                break;
            }
        }
        
        return res;
    }
};
