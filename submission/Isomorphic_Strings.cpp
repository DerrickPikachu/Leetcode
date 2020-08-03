class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        unordered_set<char> isMapped;
        
        for (int i=0; i<s.size(); i++) {
            if (!mp.count(s[i]) && !isMapped.count(t[i])) {
                mp[s[i]] = t[i];
                isMapped.insert(t[i]);
            }
            else if (mp.count(s[i])) {
                if (mp[s[i]] != t[i])
                    return false;
            }
            else if (isMapped.count(t[i]) && !mp.count(s[i])) {
                return false;
            }
        }
        
        return true;
    }
};
