class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> mp;
        int i;
        
        for (i=0;i<numbers.size();i++) {
            auto p = mp.find(target-numbers[i]);
            
            if (p != mp.end())
                return {p->second+1,i+1};
            mp[numbers[i]] = i;
        }
    }
};
