class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len,i,p=0;
        unordered_map<int,int> mp;
        len = nums.size();
        if (len%2 == 1)
            p = 1;
        
        for (i=0;i<len;i++) {
            mp[nums[i]]++;
            if (mp[nums[i]] >= len/2 + p)
                return  nums[i];
        }
    }
};
