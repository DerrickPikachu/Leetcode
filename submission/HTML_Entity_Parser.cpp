class Solution {
private:
    unordered_map<string, char> wordMap;
public:
    Solution() {
        wordMap["quot"] = '\"';
        wordMap["apos"] = '\'';
        wordMap["amp"] = '&';
        wordMap["gt"] = '>';
        wordMap["lt"] = '<';
        wordMap["frasl"] = '\/';
    }
    
    string entityParser(string text) {
        string res, buffer;
        bool buffering = false;
        
        for (char& ch : text) {
            if (!buffering) {
                if (ch == '&') {
                    buffering = true;
                    continue;
                }
                res.push_back(ch);
            } else {
                if (ch == ';') {
                    buffering = false;
                    
                    if (wordMap.count(buffer))
                        res.push_back(wordMap[buffer]);
                    else
                        res += "&" + buffer + ";";
                    buffer.clear();
                    continue;
                } else if (ch == '&') {
                    res += "&" + buffer;
                    buffer.clear();
                    continue;
                }
                buffer.push_back(ch);
            }
        }
        
        return res;
    }
};
