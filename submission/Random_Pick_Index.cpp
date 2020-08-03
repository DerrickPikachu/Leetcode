class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
        srand((unsigned)time(NULL));
    }
    
    int pick(int target) {
        vector<int> indexCollect;
        int mapping;
        
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == target)
                indexCollect.push_back(i);
        }
        
        mapping = rand() % indexCollect.size();
        
        return indexCollect[mapping];
    }
};

// ["Solution","pick"]
// [[[1,2,3,3,3]],[3]]

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
