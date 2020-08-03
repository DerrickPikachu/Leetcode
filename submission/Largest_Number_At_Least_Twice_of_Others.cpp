class Node {
public:
    int num,index;
    void input(int element,int local) {
        num = element;
        index = local;
    }
    Node operator=(Node get) {
        num = get.num;
        index = get.index;
        return *this;
    }
};
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.empty())   return -1;
        if (nums.size() == 1) return 0;
        Node max,second;
        int i,len;
        len = nums.size();
        
        if (nums[0] >= nums[1]) {
            max.input(nums[0],0);
            second.input(nums[1],1);
        }
        else {
            max.input(nums[1],1);
            second.input(nums[0],0);
        }
        for (i=2;i<len;i++) {
            if (max.num < nums[i]) {
                second = max;
                max.input(nums[i],i);
            }
            else if (second.num < nums[i])
                second.input(nums[i],i);
        }
        if (max.num >= second.num*2)
            return max.index;
        else return -1;
    }
};
