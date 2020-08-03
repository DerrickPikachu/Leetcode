class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<vector<int>> stringContent(words.size(), vector<int>(26, 0));
        int res = 0;
        
        for (int i=0; i<words.size(); i++) {
            for (int s=0; s<words[i].size(); s++)
                stringContent[i][words[i][s] - 'a'] = 1;
        }
        
        for (int i=0; i<words.size(); i++) {
            for (int j=i+1; j<words.size(); j++) {
                int letter = 0;
                
                for (; letter<26; letter++) {
                    if (stringContent[i][letter] == 1 && stringContent[j][letter] == 
                        1)
                        break;
                }
                
                if (letter == 26)
                    res = max(res, (int) (words[i].size() * words[j].size()));
            }
        }
        
        return res;
    }
};
