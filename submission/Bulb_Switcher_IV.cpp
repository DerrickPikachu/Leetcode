class Solution {
public:
    int minFlips(string target) {
        char cur = '0';
        int res = 0;
        
        for (char& bulb : target) {
            if (bulb != cur) {
                cur = bulb;
                res++;
            }
        }
        
        return res;
    }
};
