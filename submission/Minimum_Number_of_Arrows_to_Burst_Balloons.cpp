class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        return (a[0] == b[0])? a[1] < b[1]: a[0] < b[0];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        
        sort(points.begin(), points.end(), compare);
        vector<vector<int>> res;
        
        res.push_back(points[0]);
        
        for (int i=1; i<points.size(); i++) {
            if (res.back()[1] >= points[i][0]) {
                vector<int> tem = {points[i][0], min(res.back()[1], points[i][1])};
                res.pop_back();
                res.push_back(tem);
            }
            else
                res.push_back(points[i]);
        }
        
        return res.size();
    }
};
