class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> dp, ans;
        vector<int> saveSum;
        
        for (int i=0; i<candidates.size(); i++) {
            int num = candidates[i], counter = 0, nowSize = dp.size();
            while (num < target) {
                counter++;
                
                for (int j=0; j<nowSize; j++) {
                    int sum = saveSum[j] + num;
                    if (sum == target) {
                        ans.push_back(dp[j]);
                        ans[ans.size()-1].insert(ans[ans.size()-1].end(), counter, 
                            candidates[i]);
                    }
                    else if (sum > target)
                        continue;
                    else {
                        dp.push_back(dp[j]);
                        dp[dp.size()-1].insert(dp[dp.size()-1].end(), counter, 
                            candidates[i]);
                        saveSum.push_back(sum);
                    }
                }
                
                vector<int> tem(counter, candidates[i]);
                dp.push_back(tem);
                saveSum.push_back(num);
                num += candidates[i];
            }
            if (target % candidates[i] == 0) {
                vector<int> tem(target / candidates[i], candidates[i]);
                ans.push_back(tem);
            }
        }
        
        return ans;
    }
};
