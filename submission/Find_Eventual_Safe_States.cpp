class Solution {
private:
    bool findTerminal(vector<vector<int>>& graph, vector<int>& safe, unordered_set
        <int>& st, int node) {
        if (safe[node] == -1 || st.count(node))
            return false;
        else if (safe[node] == 1)
            return true;
        st.insert(node);
        
        for (int i = 0; i < graph[node].size(); i++) {
            if (!findTerminal(graph, safe, st, graph[node][i])) {
                safe[node] = -1;
                return false;
            }
        }
        
        st.erase(node);
        safe[node] = 1;
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> safe(graph.size(), 0), res;
        
        for (int i = 0; i < graph.size(); i++) {
            if (safe[i] == 0) {
                unordered_set<int> st;
                findTerminal(graph, safe, st, i);
            }
        }
        
        for (int i = 0; i < safe.size(); i++) {
            if (safe[i] == 1)
                res.push_back(i);
        }
        
        return res;
    }
};
