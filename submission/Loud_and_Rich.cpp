class Solution {
private:
    int dfs(int target, unordered_map<int, vector<int>>& richerMap, vector<int>& 
        quiet) {
        if (richerMap[target].empty())
            return target;
        
        int quietVal = quiet[target], mostQuiet = target;
        
        for (int i=0; i<richerMap[target].size(); i++) {
            int nextTarget = richerMap[target][i], temQuiet;
            temQuiet = dfs(nextTarget, richerMap, quiet);
            
            if (quiet[temQuiet] < quietVal) {
                quietVal = quiet[temQuiet];
                mostQuiet = temQuiet;
            }
        }
        
        richerMap[target].clear();
        if (mostQuiet != target)
            richerMap[target].push_back(mostQuiet);
        
        return mostQuiet;
    }
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        if (quiet.empty())
            return vector<int>();
        
        unordered_map<int, vector<int>> richerMap;
        vector<int> ans(quiet.size());
        
        for (int i=0; i<richer.size(); i++)
            richerMap[richer[i][1]].push_back(richer[i][0]);
        
        for (int i=0; i<quiet.size(); i++) {
            ans[i] = dfs(i, richerMap, quiet);
        }
        
        return ans;
    }
};
