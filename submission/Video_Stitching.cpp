class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        if (T == 0) return 0;
        vector<int> dp(T+1, INT_MAX);
        
        dp[0] = 0;
        for (int i=1; i<=T; i++) {
            for (int j=0; j<clips.size(); j++) {
                if (clips[j][0] <= i - 1 && clips[j][1] >= i) {
                    for (int k=clips[j][0]; k<i; k++) {
                        if (dp[k] == INT_MAX)
                            break;
                        else
                            dp[i] = min(dp[i], dp[k] + 1);
                    }
                }
            }
        }
        
        return dp.back() == INT_MAX ? -1 : dp.back();
    }
};
