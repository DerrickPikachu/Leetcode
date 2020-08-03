class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> count;
        priority_queue<int, vector<int>, greater<int>> heap;
        
        for (int& num : arr)
            count[num]++;
        
        for (auto& entry : count)
            heap.push(entry.second);
        
        while (k != 0 && !heap.empty()) {
            int mini = heap.top();
            
            if (mini <= k) {
                k -= mini;
                heap.pop();
            } else {
                break;
            }
        }
        
        return heap.size();
    }
};
