class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int i,save,len = nums.size();
        for (i=0;i<k;i++) {
            save = nums[len-1];
            nums.pop_back();
            nums.insert(nums.begin(),save);
        }
    }
};
