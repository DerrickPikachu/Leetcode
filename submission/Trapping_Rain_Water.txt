class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int res = 0;
        
        for (int i = 0; i < height.size(); i++) {
            if (st.empty())
                st.push(i);
            else {
                int preHeight = 0;
                
                while (!st.empty() && height[st.top()] <= height[i]) {
                    int index = st.top();
                    int dis = i - index - 1;
                    res += dis * (height[index] - preHeight);
                    preHeight = height[index];
                    st.pop();
                }
                
                if (!st.empty())
                    res += (i - st.top() - 1) * (height[i] - preHeight);
                st.push(i);
            }
        }
        
        return res;
    }
};
