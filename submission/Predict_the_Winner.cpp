class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        int isA = (nums.size() % 2 == 0)? -1:1, length = 1;
        
        for (int i=0; i<nums.size(); i++)
            dp[i][i] = isA * nums[i];
        
        while (length < nums.size()) {
            isA = (isA == 1)? -1:1;
            
            for (int i=0; i + length < nums.size(); i++) {
                int first = isA * nums[i] + dp[i+1][i+length], last = isA * nums[i
                    +length] + dp[i][i+length-1];
                // cout << "first:" << first << "  last:" << last << endl;
                dp[i][i+length] = (isA == 1)? max(first, last):min(first, last);
                // cout << dp[i][i+length] << endl;
            }
            
            length++;
        }
        
        return dp[0][nums.size()-1] >= 0;
    }
};
