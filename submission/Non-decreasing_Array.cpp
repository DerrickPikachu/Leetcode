class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if (nums.empty())   return true;
        int save=nums.size(),i,len;
        len = nums.size();
        
        for (i=0;i<len-1;i++) {
            if (nums[i] > nums[i+1]) {
                if (save != len)
                    return false;
                else
                    save = i;
            }
            else if (save != 0 && save != len && nums[save-1] > nums[i] && nums[save] 
                > nums[i+1]) 
                return false;
            
        }
        
        return true;
    }
};
