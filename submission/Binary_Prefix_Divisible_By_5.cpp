class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        unsigned long int num = 0;
        vector<bool> res;

        for (int i=0; i<A.size(); i++) {
            num <<= 1;
            num += A[i];
            if (num % 5 == 0) {
                res.push_back(true);
                num = 0;
            }
            else
                res.push_back(false);
        }
        
        return res;
    }
};
