class Solution {
private:
    unordered_map<char, int> setKey;
    vector<string> keybroad;
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        
        for (int i=0; i<words.size(); i++) {
            int row = -1;
            bool accept = true;
            
            for (int j=0; j<words[i].size(); j++) {
                if (row < 0)
                    row = setKey[tolower(words[i][j])];
                else if (row != setKey[tolower(words[i][j])]) {
                    accept = false;
                    break;
                }
            }
            
            if (accept)
                res.push_back(words[i]);
        }
        
        return res;
    }
    
    Solution() {
        keybroad.resize(3);
        keybroad[0] = "qwertyuiop";
        keybroad[1] = "asdfghjkl";
        keybroad[2] = "zxcvbnm";
        
        for (int i=0; i<3; i++)
            for (int j=0; j<keybroad[i].size(); j++)
                setKey[keybroad[i][j]] = i + 1;
    }
};
