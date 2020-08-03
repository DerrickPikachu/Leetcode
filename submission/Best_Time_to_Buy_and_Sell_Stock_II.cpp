class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int min,i,len,ans=0,max;
        min = prices[0];
        max = prices[0];
        len = prices.size();
        
        for (i=1;i<len;i++) {
            if (prices[i] < min && min == max) {
                min = prices[i];
                max = prices[i];
            }
            else if (prices[i] > max)
                max = prices[i];
            else if (prices[i] < max) {
                ans += max-min;
                min = prices[i];
                max = prices[i];
            }
        }
        if (max > min)
            ans += max-min;
        return ans;
    }
};
