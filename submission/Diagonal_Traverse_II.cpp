class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> res;
        vector<stack<int>> levels;
        
        for (int r = 0; r < nums.size(); r++) {
            for (int c = 0; c < nums[r].size(); c++) {
                if (r + c >= levels.size()) {
                    stack<int> tem;
                    tem.push(nums[r][c]);
                    levels.push_back(tem);
                }
                else
                    levels[r+c].push(nums[r][c]);
            }
        }
        
        for (stack<int>& level : levels) {
            while (!level.empty()) {
                res.push_back(level.top());
                level.pop();
            }
        }
        
        return res;
    }
};
