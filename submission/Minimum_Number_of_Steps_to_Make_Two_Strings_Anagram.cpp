class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> sWord, tWord;
        int res = 0;
        
        for (int i=0; i<s.size(); i++) {
            sWord[s[i]]++;
            tWord[t[i]]++;
        }
        
        for (int i=0; i<26; i++) {
            char aphabet = i + 'a';
            if (tWord[aphabet] > sWord[aphabet])
                res += tWord[aphabet] - sWord[aphabet];
        }
        
        return res;
    }
};
// "bab"
// "aba"
// "leetcode"
// "practice"
// "anagram"
// "mangaar"
// "xxyyzz"
// "xxyyzz"
