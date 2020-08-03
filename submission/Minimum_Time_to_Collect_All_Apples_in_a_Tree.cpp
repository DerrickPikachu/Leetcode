class Solution {
private:
    int dfs(int node, vector<vector<int>>& tree, vector<bool>& hasApple, 
        unordered_set<int>& arrived, int len = 0) {
        // if (tree[node].empty()) {
        //     if (hasApple[node])
        //         return 2;
        //     else
        //         return 0;
        // }
         arrived.insert(node);
        
        int applePath = 0;
        for (int i = 0; i < tree[node].size(); i++) {
            int next = tree[node][i];
            if (!arrived.count(next))
                applePath += dfs(next, tree, hasApple, arrived, len + 1);
        }
        
        if (applePath == 0) {
            if (hasApple[node])
                return 2;
            else
                return 0;
        }
        
        return applePath + 2;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> tree(n);
        unordered_set<int> arrived;
        
        for (int i = 0; i < edges.size(); i++) {
            tree[edges[i][0]].push_back(edges[i][1]);
            tree[edges[i][1]].push_back(edges[i][0]);
        }
        
        int res = dfs(0, tree, hasApple, arrived);
        return (res == 0)? 0 : res - 2;
    }
};
