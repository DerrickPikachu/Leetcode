class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if (nums.empty())   return vector<int>();
        int count = 0;
        vector<int> ans;
        
        for (int i=0; i<nums.size(); i++) {
            
            if (nums[i] != i + 1) {
                int j = nums[i];
                
                if (nums[j-1] == j) {
                    count++;
                    ans.push_back(j);
                }
                while (nums[j-1] != j) {
                    if (nums[j-1] < 0) {
                        nums[j-1] = j;
                        break;
                    }
                    swap(nums[j-1], j);
                    if (nums[j-1] == j) {
                        count++;
                        ans.push_back(j);
                    }
                    else if (j-1 == i) {
                        nums[j-1] = j;
                        break;
                    }
                }
                nums[i] = (nums[i] == i+1)? i+1:-count;
            }
        }
        
        return ans;
    }
};
