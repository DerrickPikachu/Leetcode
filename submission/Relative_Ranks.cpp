class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> tem = nums;
        vector<string> res(nums.size());
        int count = 1;
        
        sort(tem.begin(), tem.end());
        
        for (int i=0; i<nums.size(); i++)
            mp[nums[i]] = i;
        
        for (int i=tem.size()-1; i>=0; i--) {
            if (count == 1)
                res[mp[tem[i]]] = "Gold Medal";
            else if (count == 2)
                res[mp[tem[i]]] = "Silver Medal";
            else if (count == 3)
                res[mp[tem[i]]] = "Bronze Medal";
            else
                res[mp[tem[i]]] = to_string(count);
            
            count++;
        }
        
        return res;
    }
};
