class StockSpanner {
private:
    vector<int> priceRecord;
    vector<int> dp;
    int count;
public:
    StockSpanner() {
        priceRecord.push_back(INT_MAX);
        dp.push_back(0);
        count = 0;
    }
    
    int next(int price) {
        int sum = 0;
        
        for (int i=count; i>=0;) {
            if (priceRecord[i] <= price) {
                sum += dp[i];
                i = i - dp[i];
            }
            else {
                dp.push_back(sum + 1);
                break;
            }
        }
        
        count++;
        priceRecord.push_back(price);
        return dp.back();
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
