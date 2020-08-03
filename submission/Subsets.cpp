class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tem;
        ans.push_back(tem);
        
        for (int i=0; i<nums.size(); i++) {
            int originalSize = ans.size();
            for (int j=0; j<originalSize; j++) {
                vector<int> newSet = ans[j];                                         
                                        
                newSet.push_back(nums[i]);
                ans.push_back(newSet);
            }
            // cout << i << endl;
        }
        
        return ans;
    }
};
