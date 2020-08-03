class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_set<int> st;
        int pre, count = 0, ans = 0;
        
        for (int i=0; i<nums.size(); i++) {
            pre = i;
            while (!st.count(pre)) {
                st.insert(pre);
                pre = nums[pre];
                count++;
            }
            ans = (ans < count)? count:ans;
            count = 0;
        }
        
        return ans;
    }
};
