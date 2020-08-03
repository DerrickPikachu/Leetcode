class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res(1, 1);
        stack<int> st;
        int previous = 1;
        
        while (res.size() != n) {
            int current;
            if (previous * 10 <= n) {
                if (previous % 10 != 9)
                    st.push(previous + 1);
                current = previous * 10;
            }
            else if (previous % 10 == 9 || previous + 1 > n) {
                current = st.top();
                st.pop();
            }
            else {
                current = previous + 1;
            }
            
            res.push_back(current);
            previous = current;
        }
        
        return res;
    }
};
