class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> dpMap;
        vector<vector<string>> strRecord(16+1, vector<string>());
        int res = 0;
        
        for (int i=0; i<words.size(); i++)
            strRecord[words[i].size()].push_back(words[i]);
        
        for (int i=1; i<=16; i++) {
            vector<string> _words = strRecord[i];
            
            for (int j=0; j<_words.size(); j++) {
                int maxLen = 1;
                
                for (int k=0; k<_words[j].size(); k++) {
                    string tem = _words[j];
                    
                    tem.erase(k, 1);
                    if (dpMap.count(tem))
                        maxLen = max(maxLen, dpMap[tem] + 1);
                }
                
                dpMap[_words[j]] = maxLen;
                res = max(res, maxLen);
            }
        }
        
        return res;
    }
};
