class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() < 3) return -1;
        int sum=0,i,len,plus=0;
        len = nums.size();
        
        for (i=0;i<len;i++)
            sum += nums[i];
        if (sum-nums[0] == 0)   return 0;
        for (i=1;i<len;i++) {
            plus += nums[i-1];
            if ((sum-nums[i])%2 != 0)
                continue;
            else if (plus == (sum-nums[i])/2)
                return i;
        }
        return -1;
    }
};
