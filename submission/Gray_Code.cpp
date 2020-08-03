class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0)
            return vector<int>(1, 0);
        vector<int> res(2, 0);
        int twoPower = 2, bits = 2;
        res[1] = 1;
        
        while (bits <= n) {
            for (int i = res.size() - 1; i >= 0; i--)
                res.push_back(res[i] + twoPower);
            twoPower = pow(2, bits);
            bits++;
        }
        
        return res;
    }
};
