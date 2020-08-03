class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int xorSum = 0, res = 0;
        
        for (int start = 0; start < arr.size(); start++) {
            for (int end = start; end < arr.size(); end++) {
                xorSum ^= arr[end];
                if (xorSum == 0)
                    res += end - start;
            }
            xorSum = 0;
        }
        
        return res;
    }
};
