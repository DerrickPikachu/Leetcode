class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int mini = INT_MAX;
        vector<vector<int>> res;
        
        for (int i=1; i<arr.size(); i++) {
            int diff = arr[i] - arr[i-1];\
            vector<int> tem(2);
            tem[0] = arr[i-1];
            tem[1] = arr[i];
            
            if (diff <= mini) {
                if (diff < mini) {
                    res.clear();
                    mini = diff;
                }
                res.push_back(tem);
            }
        }
        
        return res;
    }
};
