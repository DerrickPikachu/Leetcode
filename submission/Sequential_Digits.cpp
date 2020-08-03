class Solution {
private:
    int nextNum(int next, int& num, int& digit) {
        if (num > 9) {
            num = 1;
            digit *= 10;
            next = 0;
            for (long int i=1; i<=digit; i*=10) {
                next *= 10;
                next += num;
                num++;
            }
        }
        else {
            next = (next % digit) * 10 + num;
            num++;
        }
        return next;
    }
    
public:
    vector<int> sequentialDigits(int low, int high) {
        int next = 0, digit = 1, num, lowLen = 1;
        vector<int> res;
        
        while (low / digit >= 10) {
            digit *= 10;
            lowLen++;
        }
        
        num = low / digit;
        while(next < low) {
            next = nextNum(next, num, digit);
        }
        
        while (next < high) {
            res.push_back(next);
            next = nextNum(next, num, digit);
        }
        
        return res;
    }
};
