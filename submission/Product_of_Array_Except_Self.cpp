class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // if (nums.empty()) return vector<int>();
        vector<int> forward(nums.size() + 1);
        vector<int> backward(nums.size() + 1);
        vector<int> res(nums.size());
        
        forward[0] = 1;
        backward[backward.size()-1] = 1;
        
        for (int i=1; i<forward.size(); i++)
            forward[i] = forward[i-1] * nums[i-1];
        for (int j=backward.size()-2; j>=0; j--)
            backward[j] = backward[j+1] * nums[j];
        
        for (int i=0; i<nums.size(); i++)
            res[i] = forward[i] * backward[i+1];
        
        return res;
    }
};
