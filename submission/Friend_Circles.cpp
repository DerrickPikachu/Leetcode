
class Solution {
private:
    void DFS(vector<vector<int>>& M, unordered_set<int>& st, int start) {
        // if (st.count(start)) return;
        st.insert(start);
        for (int j=0; j<M[start].size(); j++) {
            if (M[start][j] && !st.count(j))
                DFS(M, st, j);
        }
    }
    
public:
    int findCircleNum(vector<vector<int>>& M) {
        unordered_set<int> st;
        int conponent = 0;
        
        for (int i=0; i<M.size(); i++) {
            if (!st.count(i)) {
                DFS(M, st, i);
                conponent++;
            }
        }
        
        return conponent;
    }
};
