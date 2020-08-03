class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_map<string, string> find;
        vector<string> res;
        
        for (int i=0; i<folder.size(); i++)
            find[folder[i]] = folder[i];
        
        for (int i=0; i<folder.size(); i++) {
            string parent = "/";
            
            for (int s=1; s<folder[i].size(); s++) {
                if (folder[i][s] == '/') {
                    if (find.count(parent))
                        find[folder[i]] = find[parent];
                }
                parent.push_back(folder[i][s]);
            }
        }
        
        for (int i=0; i<folder.size(); i++) {
            if (find[folder[i]] == folder[i])
                res.push_back(folder[i]);
        }
        
        return res;
    }
};
