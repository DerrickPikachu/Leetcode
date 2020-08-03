class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        int next = 2;
        if (n % 2 != 0) {
            res.push_back(0);
            n--;
        }
        
        while (n != 0) {
            res.push_back(next / 2);
            res.push_back(-(next / 2));
            next += 2;
            n -= 2;
        }
        
        return res;
    }
};
