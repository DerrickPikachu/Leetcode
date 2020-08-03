class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int mid = (left + right)/2;
            bool valid = false;
            
            if (mid % 2 == 0) {
                //index even
                valid = (nums[mid] == nums[mid+1])? true:false;
            }
            else {
                //index odd
                valid = (nums[mid] == nums[mid-1])? true:false;
            }
            
            if (valid)
                left = mid + 1;
            else 
                right = mid;
        }
        
        return nums[left];
    }
};
