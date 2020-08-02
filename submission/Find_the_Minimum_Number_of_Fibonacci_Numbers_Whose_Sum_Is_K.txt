class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        int first = 0, second = 1, res = 1;
        
        k--;
        while (k != 0) {
            if (k >= first) {
                int tem = first + second;
                k -= first;
                first = second;
                second = tem;
            } else {
                first = 0;
                second = 1;
                k--;
                res++;
            }
        }
        
        return res;
    }
};
