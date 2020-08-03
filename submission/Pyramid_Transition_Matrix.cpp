class Solution {
private:
    bool dfs(string bottom, unordered_map<string, vector<char>>& mp, string next) {
        string tem;
        cout << bottom << " " << next << endl;
        
        if (bottom.size() == 1) {
            if (next.size() == 1)
                return true;
            bottom = next;
            next = "";
        }
        
        tem = bottom.substr(0, 2);
        
        if (mp.count(tem)) {
            next.push_back('0');
            for (int j=0; j<mp[tem].size(); j++) {
                next[next.size()-1] = mp[tem][j];
                if (dfs(bottom.substr(1, bottom.size()-1), mp, next))
                    return true;
            }
        }
        
        return false;
    }
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> mp;
        
        for (int i=0; i<allowed.size(); i++) {
            string tem = allowed[i].substr(0, 2);
            mp[tem].push_back(allowed[i][2]);
        }
        
        return dfs(bottom, mp, "");
    }
};
