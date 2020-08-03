class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        vector<char> record;
        string ans;
        
        for (int i=0; i<s.size(); i++) {
            if (!mp.count(s[i])) {
                mp[s[i]] = 1;
                record.push_back(s[i]);
            }
            else
                mp[s[i]]++;
        }
        
        for (int i=0; i<record.size(); i++) {
            int times = mp[record[i]], j = 0, count = 0;
            for (; j<ans.size() && mp[record[i]] < mp[ans[j]]; j += mp[ans[j]]) {}
            while (count < mp[record[i]]) {
                ans.insert(ans.begin() + j, record[i]);
                count++;
            }
        }
        
        return ans;
    }
};
