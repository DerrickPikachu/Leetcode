bool compare(string a, string b) {
    return a.size() > b.size();
}

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), compare);
        string combine = "";
        vector<int> index(words.size(), 0);
        unordered_map<string, int> posMap;
        
        for (int i=0; i<words.size(); i++) {
            if (!posMap.count(words[i])) {
                int start = combine.size();
                index[i] = combine.size();
                combine += words[i] + "#";
                
                for (int j=0; j<words[i].size(); j++, start++) {
                    string key = words[i].substr(j, words[i].size() - j);
                    posMap[key] = start;
                }
            }
            else
                index[i] = posMap[words[i]];
        }
        
        return combine.size();
    }
};
