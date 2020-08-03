class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> nameCounter;
        vector<string> res;
        
        for (string& folder : names) {
            if (!nameCounter.count(folder)) {
                nameCounter[folder] = 0;
                res.push_back(folder);
            } else {
                string tem = folder;
                while (nameCounter.count(tem)) {
                    nameCounter[folder]++;
                    tem = folder + "(" + to_string(nameCounter[folder]) + ")";
                }
                res.push_back(tem);
                nameCounter[tem] = 0;
            }
        }
        
        return res;
    }
};
