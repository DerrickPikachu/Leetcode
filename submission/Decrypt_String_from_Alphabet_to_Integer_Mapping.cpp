class Solution {
public:
    string freqAlphabets(string s) {
        unordered_map<string, char> charMap;
        string res;
        
        for (int i=1; i<=26; i++) {
            string tem = to_string(i);
            if (i >= 10)
                tem += "#";
            charMap[tem] = i + 'a' - 1;
        }
        
        for (int i=0; i<s.size(); i++) {
            string tem;
            tem.push_back(s[i]);
            if (s[i] == '#') {
                tem = s.substr(i-2, 3);
                res.pop_back();
                res.pop_back();
            }
            
            res.push_back(charMap[tem]);
        }
        
        return res;
    }
};
