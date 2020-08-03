class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0)
            return false;
        map<int, int> count;
        
        for (int i=0; i<nums.size(); i++)
            count[nums[i]]++;
        
        for (auto& it : count) {
            if (it.second != 0) {
                int need = it.second;
                
                for (int i=1; i<k; i++) {
                    if (count[it.first + i] < need)
                        return false;
                    count[it.first + i] -= need;
                }
            }
        }
        
        return true;
    }
};
