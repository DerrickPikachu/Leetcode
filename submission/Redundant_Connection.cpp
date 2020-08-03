class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> mp;
        unordered_set<int> st;
        vector<int> pair(2);
        
        for (int i=0; i<edges.size(); i++) {
            int a=edges[i][0], b = edges[i][1];
            if (!mp.count(a) && !mp.count(b)) {
                vector<int> arrA, arrB;
                arrA.push_back(b);
                arrB.push_back(a);
                mp[a] = arrA;
                mp[b] = arrB;
            }
            else if (mp.count(b) && !mp.count(a)) {
                vector<int> arr;
                arr.push_back(b);
                mp[b].push_back(a);
                mp[a] = arr;
            }
            else if (mp.count(a) && !mp.count(b)) {
                vector<int> arr;
                arr.push_back(a);
                mp[a].push_back(b);
                mp[b] = arr;
            }
            else {
                if (DFS(mp, a, b, st)) {
                    pair[0] = a;
                    pair[1] = b;
                }
                st.clear();
                mp[a].push_back(b);
                mp[b].push_back(a);
            }
        }
        
        return pair;
    }
    
    bool DFS(unordered_map<int, vector<int>>& mp, int start, int end, unordered_set
        <int>& st) {
        if (start == end) return true;
        else {
            for (int i=0; i<mp[start].size(); i++) {
                if (!st.count(mp[start][i])) {
                    st.insert(mp[start][i]);
                    if (DFS(mp, mp[start][i], end, st))
                        return true;
                }
            }
            return false;
        }
    }
};
