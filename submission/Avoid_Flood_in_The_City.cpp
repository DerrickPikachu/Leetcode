class Solution {
private:
    class Compare {
    public:
        bool operator() (pair<int, int>& a, pair<int, int>& b) {
            if (a.second < b.second)
                return false;
            else
                return true;
        }
    };
    
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int, stack<int>> lakeSts;
        vector<int> res(rains.size(), 1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> heap;
        unordered_set<int> full;
        
        for (int i = rains.size() - 1; i >= 0; i--) {
            if (!lakeSts.count(rains[i]))
                lakeSts[rains[i]].push(INT_MAX);
            lakeSts[rains[i]].push(i);
        }
        
        for (int i = 0; i < rains.size(); i++) {
            if (rains[i] > 0) {
                res[i] = -1;
                
                if (!full.count(rains[i])) {
                    // The Lake is dried, so there is no flood
                    // After raining, the lake become full, and I pop the next 
                        raining day in the stack
                    stack<int>& st = lakeSts[rains[i]];
                    full.insert(rains[i]);
                    st.pop();
                    heap.push(pair<int, int>(rains[i], st.top()));
                } else {
                    // The lake is full, and it rain again without drying.
                    return vector<int>();
                }
            } else if (!heap.empty()){
                // Choose a lake to dry
                pair<int, int> lake = heap.top();
                heap.pop();
                full.erase(lake.first);
                res[i] = lake.first;
            }
        }
        
        return res;
    }
};
