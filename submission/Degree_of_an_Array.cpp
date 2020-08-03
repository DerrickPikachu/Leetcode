class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> mp;
        unordered_map<int,int> count;
        int i,len,degree=1,distance=1;
        len = nums.size();
        
        for (i=0;i<len;i++) {
            if (!mp.count(nums[i])) {
                mp[nums[i]] = i;
                count[nums[i]]++;
            }
            else {
                count[nums[i]]++;
                if (degree < count[nums[i]]) {
                    degree = count[nums[i]];
                    distance = i - mp[nums[i]]+1;
                }
                else if (distance > i - mp[nums[i]]+1 && degree == count[nums[i]])
                    distance = i - mp[nums[i]]+1;
            }
        }
        
        return distance;
    }
};
