class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j=0;
        
        for (int i=0; i<pushed.size(); i++) {
            if (j >= popped.size())
                return false;
            while (!st.empty() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
            st.push(pushed[i]);
        }
        
        for (; j<popped.size(); j++) {
            if (st.empty() || st.top() != popped[j])
                return false;
            st.pop();
        }
        
        return true;
    }
};
