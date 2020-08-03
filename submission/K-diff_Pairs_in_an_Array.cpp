class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        unordered_map<int,int> map;
        sort(nums.begin(),nums.end());
        int i,count=0,len;
        bool check_dup=false;
        len = nums.size();
        
        for (i=0;i<len;i++) {
            if (map.count(nums[i])) {
                if (k == 0 && !check_dup) {
                    count++;
                    check_dup = true;
                }
            }
            else {
                map.insert({nums[i],i});
                check_dup = false;
                if (map.count(nums[i]-k) && k!=0)
                    count++;
            }
        }
        
        return count;
    }
};
