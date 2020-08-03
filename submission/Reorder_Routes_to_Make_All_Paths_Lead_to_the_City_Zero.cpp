class Solution {
private:
    void dfs(int current, int previous, vector<vector<int>>& edgeList, int& count) {
        for (int& nextCity : edgeList[current]) {
            if (abs(nextCity) != previous) {
                if (nextCity > 0)
                    count++;
                dfs(abs(nextCity), current, edgeList, count);
            }
        }
    }
    
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        // Fuck you vector, this fucking declare need O(n*n)
        // vector<vector<int>> graph(n, vector<int>(n));
        vector<vector<int>> edgeList(n);
        int count = 0;
        
        // Build the graph, toward = 1, backward = -1
        for (vector<int>& connection : connections) {
            // graph[connection[0]][connection[1]] = 1;
            // graph[connection[1]][connection[0]] = -1;
            edgeList[connection[1]].push_back(-connection[0]);
            edgeList[connection[0]].push_back(connection[1]);
        }
        
        dfs(0, -1, edgeList, count);
        return count;
    }
};
