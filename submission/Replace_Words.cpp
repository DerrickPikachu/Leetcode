class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        stringstream delim(sentence);
        string word, res;
        
        while (getline(delim, word, ' ')) {
            string tem;
            
            for (int i=0; i<dict.size(); i++) {
                if (word.find(dict[i]) == 0)
                    tem = (tem.size() > dict[i].size() || tem.empty())? dict[i]:tem;
            }
            
            res += (tem.empty())? word:tem;
            res += " ";
        }
        
        res.pop_back();
        return res;
    }
};
