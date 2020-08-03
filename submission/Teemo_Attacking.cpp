class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) return 0;
        int total = 0;
        
        for (int i=0; i<timeSeries.size() - 1; i++) {
            if (timeSeries[i] + duration >= timeSeries[i+1])
                total += timeSeries[i+1] - timeSeries[i];
            else
                total += duration;
        }
        
        total += duration;
        
        return total;
    }
};
