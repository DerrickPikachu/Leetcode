class Solution {
private:
    int getSum(vector<int>& nums, int divisor) {
        int sum = 0;
        for (int i=0; i<nums.size(); i++) {
            sum += nums[i] / divisor;
            if (nums[i] % divisor != 0)
                sum++;
        }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = 0, left = 1, right;
        
        for (int i=0; i<nums.size(); i++) {
            if (maxi < nums[i])
                maxi = nums[i];
        }
        
        right = maxi;
        while (left < right) {
            int mid = (left + right) / 2, sum = getSum(nums, mid);
            
            if (sum <= threshold)
                right = mid;
            else
                left = mid + 1;
        }
        
        return left;
    }
};
