class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty())   return false;
        std::unordered_set<int> st;
        int len,i;
        
        len = nums.size();
        for (i=0;i<len;i++) {
            if (st.count(nums[i]) == 0)
                st.insert(nums[i]);
            else
                return true;
        }
        
        return false;
    }
};
