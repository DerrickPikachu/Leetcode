class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index,i,len;
        len = nums.size();
        
        for (i=0;i<len;i++) {
            if (nums[i] == 0){
                index = i;
                break;
            }
        }//find out the first 0 in the array
        for (i=i+1;i<len;i++) {
            if (nums[i]!=0) {
                nums[index] = nums[i];
                nums[i] = 0;
                index++;
            }
        }
    }
};
