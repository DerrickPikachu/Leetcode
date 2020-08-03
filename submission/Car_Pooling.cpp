bool compare(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), compare);
        int peoples = 0, i = 0;
        priority_queue<int, vector<int>, greater<int>> nextStation;
        unordered_map<int, int> dropOff;
        
        while (i < trips.size()) {
            bool empty = nextStation.empty();
            int next = (empty)? 0:nextStation.top();
            
            if (!empty && next <= trips[i][1]) {
                peoples -= dropOff[next];
                dropOff[next] = 0;
                nextStation.pop();
            }
            
            if (empty || (!empty && next >= trips[i][1])) {
                peoples += trips[i][0];
                nextStation.push(trips[i][2]);
                dropOff[trips[i][2]] += trips[i][0];
                i++;
            }
            
            if (peoples > capacity)
                return false;
        }
        
        return true;
    }
};
