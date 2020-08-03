class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, vector<int>> remainder;
        int sum = 0, res = 0;
        
        for (int i=0; i<A.size(); i++) {
            int _remainder;
            sum += A[i];
            
            _remainder = (sum % K >= 0)? sum % K:sum % K + K;
            res += remainder[_remainder].size();
            remainder[_remainder].push_back(i);
            
            if (_remainder == 0)
                res++;
        }
        
        return res;
    }
};
