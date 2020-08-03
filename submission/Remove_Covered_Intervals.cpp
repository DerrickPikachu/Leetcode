bool compare(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<int> order(1, -1);
        
        for (int i=0; i<intervals.size(); i++) {
            if (intervals[i][1] > order.back())
                order.push_back(intervals[i][1]);
        }
        
        return order.size() - 1;
    }
};
