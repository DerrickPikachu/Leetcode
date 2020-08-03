class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        int res = 0;
        
        for (int i=0; i<arr.size(); i++) {
            if (dp.count(arr[i] - difference)) {
                dp[arr[i]] = max(dp[arr[i]], dp[arr[i]-difference] + 1);
            }
            else {
                dp[arr[i]] = 1;
            }
            
            res = max(dp[arr[i]], res);
        }
        
        return res;
    }
};
