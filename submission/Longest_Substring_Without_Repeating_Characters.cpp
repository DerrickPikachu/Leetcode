class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, count = 0, start = 0;
        unordered_map<char, int> mp;
        
        for (int i=0; i<s.size(); i++) {
            if (!mp.count(s[i])) {
                count++;
                mp[s[i]] = i;
            }
            else {
                if (mp[s[i]] < start)
                    count++;
                else {
                    int offset = mp[s[i]] - start;
                    start = mp[s[i]] + 1;
                    count = count - offset;
                }
                mp[s[i]] = i;
            }
            
            res = max(res, count);
        }
        
        return res;
    }
};
