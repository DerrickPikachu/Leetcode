class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size()+1, 0);
        nums.insert(nums.begin(), 0);
        int maximum = INT_MIN, minidp = 0;
        
        for (int i=1; i<nums.size(); i++) {
            dp[i] = dp[i-1] + nums[i];
            
            if (maximum < dp[i] - minidp) {
                maximum = dp[i] - minidp;
            }
            if (minidp > dp[i]) {
                minidp = dp[i];
            }
        }
        
        return maximum;
    }
};
