class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i,replace=-1,len=0;
        
        for (i=0;i<nums.size();i++) {
            if (nums[i] == val) {
                if (replace == -1)
                    replace = i;
                len++;
            }
            else {
                if (replace == -1)
                    continue;
                else {
                    swap(nums[replace],nums[i]);
                    replace++;
                }
            }
        }
        
        return nums.size()-len;
    }
};
