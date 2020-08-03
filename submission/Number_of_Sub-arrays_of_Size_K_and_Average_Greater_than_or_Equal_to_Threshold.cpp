class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        threshold = threshold * k;
        int index = 0, window = 0, res = 0;
        
        for (; index < k; index++)
            window += arr[index];
        
        if (window >= threshold)
            res++;
        
        for (; index < arr.size(); index++) {
            window += arr[index] - arr[index - k];
            if (window >= threshold)
                res++;
        }
        
        return res;
    }
};
