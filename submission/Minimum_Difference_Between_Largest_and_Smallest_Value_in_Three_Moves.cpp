class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() <= 4)
            return 0;
        int left = 3, right = nums.size() - 1, res = INT_MAX;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < 4; i++) {
            res = min(res, nums[right] - nums[left]);
            left--;
            right--;
        }
        
        return res;
    }
};
