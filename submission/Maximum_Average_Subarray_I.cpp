class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int maxSum = 0;
        int sum = 0;
        for(int i = 0; i < k; i++)
        {
            sum += nums[i];
        }
        
        maxSum = sum;
        for(int i = k; i < nums.size(); i++)
        {
            sum = sum + nums[i] - nums[i-k];
            maxSum = max (maxSum, sum);
        }
        
        return (double) maxSum / k;
    }
};