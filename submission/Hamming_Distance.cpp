class Solution {
public:
    int romanToInt(string s) {
        return 0;
    }
    
    int hammingDistance(int n1, int n2) {
        int count = 0;
        
        while (n1 != 0 || n2 != 0) {
            if (n1 % 2 != n2 % 2)
                count++;
            n1 /= 2;
            n2 /= 2;
        }
        
        return count;
    }
};
