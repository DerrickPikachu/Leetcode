class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> counter;
        int res = 0;
        
        for (int i = 0, j = -1; i < s.size(); i++) {
            counter[s[i]]++;
            while (counter['a'] != 0 && counter['b'] != 0 && counter['c'] != 0) {
                res += s.size() - i;
                counter[s[++j]]--;
            }
        }
        
        return res;
    }
};
