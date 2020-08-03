class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int> prefix(k + 1, 0), postfix(k + 1, 0);
        int res = 0;
        
        for (int i = 1; i <= k; i++) {
            prefix[i] = prefix[i-1] + cardPoints[i-1];
            postfix[i] = postfix[i-1] + cardPoints[cardPoints.size()-i];
        }
        
        for (int i = 0; i <= k; i++)
            res = max(res, prefix[i] + postfix[k-i]);
        
        return res;
    }
};
