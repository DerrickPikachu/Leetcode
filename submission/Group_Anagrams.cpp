class Solution {
private:
    string getKey(string str) {
        string res;
        vector<int> charMp(26, 0);
        
        for (int i=0; i<str.size(); i++) {
            int index = str[i] - 'a';
            charMp[index]++;
        }
        
        for (int i=0; i<26; i++) {
            if (charMp[i] != 0)
                res.append(charMp[i], i + 'a');
        }
        
        return res;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> anagram;
        vector<vector<string>> res;
        
        for (int i=0; i<strs.size(); i++) {
            string key = getKey(strs[i]);
            
            if (!anagram.count(key)) {
                res.push_back(vector<string>(1, strs[i]));
                anagram[key] = res.size() - 1;
            }
            else
                res[anagram[key]].push_back(strs[i]);
            
        }
        
        return res;
    }
};
