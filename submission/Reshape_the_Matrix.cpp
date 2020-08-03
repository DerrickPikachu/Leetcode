class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int size = nums.size() * nums[0].size();
        if (nums.empty() || size != r*c)   return nums;
        vector<vector<int>> NewArray(r);
        int i,j,s_r=0,s_c;
        
        s_c = c;
        for (i=0;i<nums.size();i++) {
            for (j=0;j<nums[i].size();j++) {
                NewArray[s_r].push_back(nums[i][j]);
                if (--s_c == 0) {
                    s_r++;
                    s_c = c;
                }
            }
        }
        return NewArray;
    }
};
