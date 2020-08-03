class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.empty())   return false;
        unordered_map<int,int> mp;
        int i,len,diff;
        len = nums.size();
        
        for (i=0;i<len;i++) {
            if (mp.count(nums[i]) == 0)
                mp.insert({nums[i],i});
            else {
                diff = i - mp[nums[i]];
                if (diff <= k)
                    return true;
                else 
                    mp[nums[i]] = i;
            }
        }
        
        return false;
    }
};
