class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())   return false;
        unordered_map<char, int> smp;
        
        for (int i=0; i<s.size(); i++)
            smp[s[i]]++;
        for (int i=0; i<t.size(); i++) {
            if (smp[t[i]] > 0) {
                smp[t[i]]--;
            }
            else
                return false;
        }
        return true;
    }
};
