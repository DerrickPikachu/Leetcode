class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int step = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                if (step >= 0)
                    return false;
                step = k;
            }
            step--;
        }
        
        return true;
    }
};
