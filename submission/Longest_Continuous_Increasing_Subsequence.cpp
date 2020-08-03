class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int maxlen=1,nowlen=1,arraylen,i;
        arraylen = nums.size();
        
        for (i=1;i<arraylen;i++) {
            if (nums[i] > nums[i-1]) {
                nowlen++;
                if (maxlen < nowlen)
                    maxlen++;
            }
            else {
                nowlen = 1;
            }
        }
        
        return maxlen;
    }
};
