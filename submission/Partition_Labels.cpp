class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;
        vector<vector<int>> dp(1);
        dp[0].push_back(1);
        mp[s[0]] = 0;
        for (int i=1; i<s.size(); i++) {
            if (mp.count(s[i])) {
                int partStart = mp[s[i]];
                for (int j = partStart+1; j < i; j++) {
                    if (mp[s[j]] < partStart)
                        partStart = j - dp[j][dp[j].size() - 1] + 1;
                }
                (partStart == 0)? dp.push_back(vector<int>()):dp.push_back
                    (dp[partStart - 1]);
                dp[i].push_back(i - partStart + 1);
            }
            else {
                dp.push_back(dp[i-1]);
                dp[i].push_back(1);
                mp[s[i]] = i;
            }
        }
        
        return dp[dp.size()-1];
    }
};
