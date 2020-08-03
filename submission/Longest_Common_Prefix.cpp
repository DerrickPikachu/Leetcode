class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string longer;
        if (strs.empty())   return longer;
        string now = strs[0],shorter;
        int len = strs.size(),i;
        
        for (i=1; i<len; i++) {
            if (strs[i].size() >= now.size()) {
                longer = strs[i];
                shorter = now;
            }
            else {
                longer = now;
                shorter = strs[i];
            }
            now.clear();
            for (int j=0; j<shorter.size(); j++) {
                if (longer[j] == shorter[j])
                    now.push_back(longer[j]);
                else
                    break;
            }
        }
        
        return now;
    }
};
