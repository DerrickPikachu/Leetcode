class Solution {
public:
    int arrangeCoins(int n) {
        long left_index,right_index,mid_index,time;
        long mid,nlong;
        
        nlong = (long)n;
        left_index = 1;
        right_index = nlong;
        mid_index = (nlong+1)/2;
        mid = (mid_index+1)*mid_index/2;
        
        while(left_index <= right_index) {
            if (mid > nlong)
                right_index = mid_index-1;
            else if (mid < nlong)
                left_index = mid_index+1;
            else 
                return mid_index;
            mid_index = (right_index + left_index)/2;
            mid = (mid_index+1)*mid_index/2;
        }
        
        return left_index-1;
    }
};
