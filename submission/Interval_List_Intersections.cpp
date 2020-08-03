/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> intervalIntersection(vector<Interval>& a, vector<Interval>& b) {
        int startTime, endTime;
        vector<Interval> ans;
        
        for (int i=0, j=0; i<a.size() && j<b.size();) {
            startTime = (a[i].start > b[j].start)? a[i].start:b[j].start;
            // endTime = (a[0].end < b[0].end)? a[0].end:b[0].end;
            if (a[i].end < b[j].end) {
                endTime = a[i].end;
                i++;
            }
            else {
                endTime = b[j].end;
                j++;
            }
            
            if (endTime >= startTime)
                ans.push_back(Interval(startTime, endTime));
        }
        
        return ans;
    }
};
