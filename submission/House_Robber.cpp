class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() >= 3) {
            int i=2, first, second;
            if (nums[0] > nums[1])
                first = 0, second = 1;
            else first = 1, second = 0;
            
            for (; i<nums.size() && nums.size() >= 3; i++) {
                if (first != i-1)
                    nums[i] += nums[first];
                else
                    nums[i] += nums[second];
                if (nums[i] >= nums[first])
                    second = first, first = i;
                else if (nums[i] >= nums[second])
                    second = i;
            }
            return nums[first];
        }
        else
            return (nums.size() == 2)? max(nums[0], nums[1]):nums[0];
    }
};
