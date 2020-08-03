class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> noOutgoing, outgoing;
        
        for (vector<string>& path : paths) {
            if (!outgoing.count(path[0]))
                outgoing.insert(path[0]);
            if (noOutgoing.count(path[0]))
                noOutgoing.erase(path[0]);
            if (!outgoing.count(path[1]) && !noOutgoing.count(path[1]))
                noOutgoing.insert(path[1]);
        }
        
        return *noOutgoing.begin();
    }
};
