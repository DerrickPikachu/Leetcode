class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        if (nums.empty())   return 0;
        int max=0;
        sort(nums.begin(), nums.end());
        
        for (int i=0;i<nums.size();i+=2)
            max += nums[i];
        
        return max;
    }
};
