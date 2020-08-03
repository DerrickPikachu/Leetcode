class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        
        while (left <= right) {
            int mid = (left + right)/2;
            if (nums[left] < nums[right]) {
                right = left;
                break;
            }
            else if (nums[left] <= nums[mid])
                left = mid + 1;
            else if (nums[left] > nums[mid])
                right = mid;
        }
        
        return nums[right];
    }
};
