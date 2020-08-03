class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if (nums.empty()) return 0;
        int maxlen=0,nowlen=0,len,i;
        len = nums.size();
        
        for (i=0;i<len;i++) {
            if (nums[i] == 1) {
                nowlen++;
                if (maxlen < nowlen)
                    maxlen++;
            }
            else {
                nowlen = 0;
            }
        }
        
        return maxlen;
    }
};
