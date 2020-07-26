class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = 0, remainder = 0;
        
        while (numBottles != 0) {
            int nextNum = (numBottles + remainder) / numExchange;
            res += numBottles;
            remainder = (numBottles + remainder) % numExchange;
            numBottles = nextNum;
        }
        
        return res;
    }
};
