class Solution {
private:
    void DFS(vector<vector<int>>& graph, int node, vector<vector<int>>& paths, vector
        <int>& curr) {
        curr.push_back(node);
        
        if (node == graph.size() - 1)
            paths.push_back(curr);
        else {
            for (int i=0; i<graph[node].size(); i++)
                DFS(graph, graph[node][i], paths, curr);
        }
        
        curr.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph, int node = 0
        ) {
        vector<vector<int>> paths;
        vector<int> curr;
        
        DFS(graph, 0, paths, curr);
        return paths;
    }
};
