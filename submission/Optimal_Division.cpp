class Solution {
private:
    string res;
    
    void track(vector<int>& nums, float pre, int index, string priority, float& 
        maxDiv) {
        float current;
        string tem;
        
        if (index >= nums.size()) {
            if (maxDiv < pre) {
                res = priority;
                maxDiv = pre;
            }
            return;
        }
        
        for (int i=index; i<nums.size(); i++) {
            if (i == index) {
                current = nums[i];
                tem = to_string(nums[i]);
                track(nums, pre / current, i + 1, priority + "/" + tem, maxDiv);
            }
            else {
                current /= nums[i];
                tem += "/" + to_string(nums[i]);
                track(nums, pre / current, i + 1, priority + "/(" + tem + ")", maxDiv
                    );
            }
        }
    }
public:
    string optimalDivision(vector<int>& nums) {
        float maxDiv = 0;
        res = "";
        track(nums, (float)nums[0], 1, to_string(nums[0]), maxDiv);
        return res;
    }
};
