class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> res(nums.size(), -1);
        
        st.push(0);
        for (int i=1; i<2*nums.size(); i++) {
            int index = i % nums.size();
            
            while (!st.empty() && nums[st.top()] < nums[index]) {
                res[st.top()] = nums[index];
                st.pop();
            }
            
            st.push(index);
        }
        
        return res;
    }
};
