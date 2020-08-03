class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max,i,len;
        len = nums.size();
        sort(nums.begin(),nums.end());
        
        if (nums[len-1] <= 0)
            return  nums[len-1]*nums[len-2]*nums[len-3];
        else if (nums[len-3] <= 0)
            return  nums[len-1]*nums[0]*nums[1];
        else if (nums[0]*nums[1] > nums[len-2]*nums[len-3])
            return  nums[len-1]*nums[0]*nums[1];
        else 
            return  nums[len-1]*nums[len-2]*nums[len-3];
        
    }
};
