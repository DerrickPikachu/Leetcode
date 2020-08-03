class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size());
        int last, last2, res;
        
        last = -1;
        last2 = -1;
        dp[0] = nums[0];
        res = nums[0];
        
        for (int i=1; i<nums.size(); i++) {
            dp[i] = nums[i];
            
            if (nums[i-1] != nums[i] - 1)
                dp[i] = max(dp[i], dp[i-1] + nums[i]);
            if (last2 >= 0 && nums[last2] != nums[i] - 1)
                dp[i] = max(dp[i], dp[last2] + nums[i]);
            if (last >= 0)
                dp[i] = max(dp[i], dp[last] + nums[i]);
            
            res = max(res, dp[i]);
            if (nums[i] != nums[i-1]) {
                last = last2;
                last2 = i-1;
            }
        }
        
        return res;
    }
};
