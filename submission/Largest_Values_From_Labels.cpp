class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int 
        num_wanted, int use_limit) {
        unordered_map<int, vector<int>> mapLabel;
        unordered_map<int, int> labelCount;
        priority_queue<int> biggest(values.begin(), values.end());
        int n = values.size(), res = 0;
        
        for (int i=0; i<n; i++)
            mapLabel[values[i]].push_back(labels[i]);
        
        while(num_wanted > 0 && !biggest.empty() && biggest.top() > 0) {
            int next = biggest.top();
            biggest.pop();
            // cout << next << endl;
            
            if (labelCount[mapLabel[next].back()] < use_limit) {
                res += next;
                labelCount[mapLabel[next].back()]++;
                num_wanted--;
            }
            
            mapLabel[next].pop_back();
        }
        
        return res;
    }
};
