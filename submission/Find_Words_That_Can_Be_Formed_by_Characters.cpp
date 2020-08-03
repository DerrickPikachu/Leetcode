class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> appear;
        int res = 0;
        
        for (int i=0; i<chars.size(); i++)
            appear[chars[i]]++;
        
        for (int i=0; i<words.size(); i++) {
            unordered_map<char, int> tem = appear;
            bool canFormed = true;
            
            for (int j=0; j<words[i].size(); j++) {
                if (tem[words[i][j]] != 0)
                    tem[words[i][j]]--;
                else {
                    canFormed = false;
                    break;
                }
            }
            
            if (canFormed)
                res += words[i].size();
        }
        
        return res;
    }
};
