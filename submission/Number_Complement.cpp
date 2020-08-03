class Solution {
public:
    int findComplement(int num) {
        // if (num == INT_MAX) return 0;
        long int powerOfTwo = 1;
        
        while (powerOfTwo <= num)
            powerOfTwo *= 2;
        
        return (int)(powerOfTwo - num - 1);
    }
};
