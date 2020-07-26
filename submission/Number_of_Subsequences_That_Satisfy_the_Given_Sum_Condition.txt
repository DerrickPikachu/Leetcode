class Solution {
private:
    int search(vector<int>& nums, int left, int right, int mini, int target) {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (mini + nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return right;
    }
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        long int res = 0;
        long mod = pow(10, 9) + 7;
        vector<int> pows(nums.size(), 1);
        
        for (int i = 1; i < nums.size(); i++)
            pows[i] = (pows[i-1] * 2) % mod;
        
        
        for (int i = 0; i < nums.size() && nums[i] * 2 <= target; i++) {
            int maxIndex = search(nums, i, nums.size() - 1, nums[i], target);
            int power = maxIndex - i;
            long tem = 1;
            
            res += pows[power] % mod;
            res %= mod;
        }
        
        return res;
    }
};
