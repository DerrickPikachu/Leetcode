class Solution {
public:
    bool hasAlternatingBits(int n) {
        int pre = (n % 2)? 0:1;
        
        while (n != 0) {
            int lastBit = n % 2;
            if (pre == lastBit)
                return false;
            n  = n >> 1;
            pre = lastBit;
        }
        
        return true;
    }
};
