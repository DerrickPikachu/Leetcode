class Solution {
public:
    int addDigits(int num) {
        while(num / 10 > 0) {
            int tem = 0;
            while(num / 10 > 0) {
                tem += num%10;
                num /= 10;
            }
            tem += num;
            num = tem;
        }
        return num;
    }
};
