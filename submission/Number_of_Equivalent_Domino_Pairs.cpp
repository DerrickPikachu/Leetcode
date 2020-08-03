class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int res = 0;
        unordered_map<int, unordered_map<int, int>> mp;
        
        for (int i=0; i<dominoes.size(); i++) {
            if (mp.count(dominoes[i][0]) && mp[dominoes[i][0]].count(dominoes[i][1])) 
                {
                res += mp[dominoes[i][0]][dominoes[i][1]];
            }
            if (dominoes[i][0] == dominoes[i][1]) {
                mp[dominoes[i][0]][dominoes[i][1]]++;
            }
            else {
                mp[dominoes[i][0]][dominoes[i][1]]++;
                mp[dominoes[i][1]][dominoes[i][0]]++;
            }
        }
        
        return res;
    }
};
