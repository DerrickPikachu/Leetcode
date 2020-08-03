class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> counter;
        int setSize = 0, num = 0; 
        priority_queue<int> heap;
        
        for (int i=0; i<arr.size(); i++)
            counter[arr[i]]++;
        
        for (auto& it : counter)
            heap.push(it.second);
        
        while (!heap.empty()) {
            num += heap.top();
            heap.pop();
            setSize++;
            if (num >= arr.size() / 2)
                break;
        }
        
        return setSize;
    }
};
