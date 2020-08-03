class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> dp(arr.size(),0), res;
        
        dp[0] = arr[0];
        for (int i=1; i<arr.size(); i++)
            dp[i] = dp[i-1] ^ arr[i];
        
        for (int i=0; i<queries.size(); i++) {
            int from = queries[i][0], to = queries[i][1];
            if (from - 1 >= 0)
                res.push_back(dp[to] ^ dp[from-1]);
            else
                res.push_back(dp[to]);
        }
        
        return res;
    }
};
