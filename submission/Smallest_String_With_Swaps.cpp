class Solution {
private:
    int find(vector<int>& unionFind, int i) {
        if (unionFind[i] != -1)
            return unionFind[i] = find(unionFind, unionFind[i]);
        return i;
    }
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<int> unionFind(s.size(), -1);
        vector<vector<int>> member(s.size());
        
        for (auto& pair : pairs) {
            int root1 = find(unionFind, pair[0]), root2 = find(unionFind, pair[1]);
            if (root1 != root2)
                unionFind[root2] = root1;
        }
        
        for (int i = 0; i < unionFind.size(); i++)
            member[find(unionFind, i)].push_back(i);
        
        for (int i = 0; i < member.size(); i++) {
            string ss;
            for (int& mem : member[i])
                ss += s[mem];
            sort(ss.begin(), ss.end());
            for (int j = 0; j < member[i].size(); j++)
                s[member[i][j]] = ss[j];
        }
        
        return s;
    }
};
