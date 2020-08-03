class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())   return 0;
        if (nums.size() == 1)   return 1;
        int i,save;
        
        for (i=1;i<nums.size();i++) {
            if (nums[i] == nums[i-1]) {
                while(nums[i] == nums[i-1] && i < nums.size()) {
                    nums.erase(nums.begin() + i);
                }
            }
        }
        return nums.size();
    }
};
