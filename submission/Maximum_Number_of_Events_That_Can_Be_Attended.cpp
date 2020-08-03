bool compare(vector<int>& a, vector<int>& b) {
    if (a[0] == b[0])
        return a[1] < b[1];
    else
        return a[0] < b[0];
}

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), compare);
        int day = events[0][0], res = 0;
        priority_queue<int, vector<int>, greater<int>> heap;
        
        for (int i = 0; i < events.size(); i++) {
            if (day <= events[i][0]) {
                day = events[i][0] + 1;
                res++;
            }
            else if (day > events[i][0] && day <= events[i][1]) {
                while (i < events.size() && day >= events[i][0]) {
                    heap.push(events[i][1]);
                    i++;
                }
                
                while (!heap.empty()) {
                    if (day <= heap.top()) {
                        day++;
                        res++;
                    }
                    heap.pop();
                    while (i < events.size() && day >= events[i][0]) {
                        heap.push(events[i][1]);
                        i++;
                    }
                }
                i--;
            }
        }
        
        return res;
    }
};
