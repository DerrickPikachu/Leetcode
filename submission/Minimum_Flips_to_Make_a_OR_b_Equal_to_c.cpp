class Solution {
public:
    int minFlips(int a, int b, int c) {
        int counter = (a | b) ^ c, res = 0, andResult = a & b;
        
        while (counter != 0) {
            res += counter % 2;
            if (andResult % 2 == 1)
                res += counter % 2;
            counter = counter >> 1;
            andResult = andResult >> 1;
        }
        
        return res;
    }
};
