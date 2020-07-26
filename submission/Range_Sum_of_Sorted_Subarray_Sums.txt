class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        long res = 0, mod = pow(10, 9) + 7;
        vector<long> sumArr(nums.begin(), nums.end());
        
        for (int len = 2; len <= n; len++) {
            queue<long> window;
            long sum = 0;
            
            for (int i = 0; i < n; i++) {
                window.push(sumArr[i]);
                sum += sumArr[i];
                if (window.size() > len) {
                    sum -= window.front();
                    window.pop();
                }
                if (window.size() == len)
                    sumArr.push_back(sum);
            }
        }
        
        sort(sumArr.begin(), sumArr.end());
        for (int i = left - 1; i < right; i++)
            res = (res + sumArr[i]) % mod;
        
        return (int)res;
    }
};
