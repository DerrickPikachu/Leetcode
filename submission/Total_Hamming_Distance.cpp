class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> accumulate(32, 0);
        int res = 0;
        
        for (int count=0; count<nums.size(); count++) {
            int current = nums[count];
            
            for (int shift=0; shift<32; shift++) {
                int curBit = current % 2;
                current >>= 1;
                if(curBit) {
                    res += count - accumulate[shift];
                    accumulate[shift]++;
                }
                else
                    res += accumulate[shift];
            }
        }
        
        return res;
    }
};
