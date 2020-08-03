class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if (arr.empty())    return 0;
        vector<bool> isArrive(arr.size(), false);
        int res = 0, maxIndex = -1;
        
        for (int i=0; i<arr.size(); i++) {
            if (arr[i] == i && !isArrive[i] && i > maxIndex)
                res++;
            else {
                int num = arr[i];
                if (!isArrive[i]) {
                    while (!isArrive[num]) {
                        maxIndex = max(maxIndex, num);
                        isArrive[num] = true;
                        num = arr[num];
                    }
                }
                
                if (i == maxIndex)
                    res++;
            }
            
            isArrive[i] = true;
        }
        
        return res;
    }
};
