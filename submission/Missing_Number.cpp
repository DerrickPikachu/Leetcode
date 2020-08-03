class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int cnt = nums.size();
        int sum = cnt * (cnt + 1) / 2;
        for (int i = 0; i < cnt; i++){
            sum -= nums[i];
        }
        return sum;
    }
};
