class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string> arrived;
        vector<int> position(2, 0);
        arrived.insert("0_0");
        
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == 'N') {
                position[1]++;
            } else if (path[i] == 'S') {
                position[1]--;
            } else if (path[i] == 'E') {
                position[0]++;
            } else if (path[i] == 'W') {
                position[0]--;
            }
            
            string key = to_string(position[0]) + "_" + to_string(position[1]);
            if (arrived.count(key))
                return true;
            else
                arrived.insert(key);
        }
        
        return false;
    }
};
