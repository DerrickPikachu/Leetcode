class Solution {
public:
    int binaryGap(int n) {
        int maximum = 0, count = 0;
        
        while (n % 2 != 1 && n > 0) {
            n = n >> 1;
        }
            
        while (n > 0) {
            if (n % 2 == 1) {
                maximum = (count > maximum)? count:maximum;
                count = 0;
            }
            count++;
            n = n >> 1;
        }
        
        return maximum;
    }
};
