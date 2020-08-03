class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> arr(heights.begin(), heights.end());
        sort(arr.begin(), arr.end());
        int res = 0;
        
        for (int i=0; i<heights.size(); i++) {
            if (arr[i] != heights[i])
                res++;
        }
        
        return res;
    }
};
