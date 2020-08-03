class NumArray {
private:
    vector<int> DP;
public:
    NumArray(vector<int> nums) {
        if (!nums.empty()) {
            DP.push_back(nums[0]);
            for (int i=1; i<nums.size(); i++)
                DP.push_back(nums[i] + DP[i-1]);
        }
    }
    
    int sumRange(int i, int j) {
        return (i == 0)? DP[j]:DP[j] - DP[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
