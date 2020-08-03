class Solution {
private:
    vector<int> counter(int cur, int parent, vector<vector<int>>& connect,
                 vector<int>& res, string& labels) {
        char label = labels[cur];
        vector<int> appear(26, 0);
        
        for (int i = 0; i < connect[cur].size(); i++) {
            int next = connect[cur][i];
            
            if (next != parent) {
                vector<int> tem = counter(next, cur, connect, res, labels);
                for (int i = 0; i < 26; i++)
                    appear[i] += tem[i];
            }
        }
        
        appear[label - 'a'] += 1;
        res[cur] = appear[label - 'a'];
        return appear;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> res(n, 0);
        vector<vector<int>> connect(n);
        
        for (vector<int>& edge : edges) {
            connect[edge[0]].push_back(edge[1]);
            connect[edge[1]].push_back(edge[0]);
        }
        
        counter(0, -1, connect, res, labels);
        return res;
    }
};
