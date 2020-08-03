class Solution {
private:
    int divide(vector<int>& nums, int s, int e) {
        int isFindR, isFindL;
        int mid = (s + e) / 2;
        if (s == e)
            return -1;
        
        isFindR = divide(nums, mid + 1, e);
        isFindL = divide(nums, s, mid);
        
        if (isFindR != -1 || isFindL != -1)
            return (isFindR != -1)? isFindR:isFindL;
        else {
            for (int i=s; i<=mid; i++) {
                for (int j=mid+1; j<=e; j++) {
                    if (nums[i] == nums[j])
                        return nums[i];
                }
            }
        }
        
        return -1;
    }
public:
    int findDuplicate(vector<int>& nums) {
        return divide(nums, 0, nums.size()-1);
    }
};
