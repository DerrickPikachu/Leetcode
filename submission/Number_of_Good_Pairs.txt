class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> counter;
        int res = 0;
        
        for (int& num : nums)
            counter[num]++;
        
        for (auto& it : counter) {
            int count = it.second;
            res += (count * (count - 1)) / 2;
        }
        
        return res;
    }
};
