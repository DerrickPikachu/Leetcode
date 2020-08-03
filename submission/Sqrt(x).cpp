class Solution {
public:
    int mySqrt(int x) {
        long int left=1,right,mid;
        right = (left + (long)x)/2;
        
        while (left <= right) {
            mid = (left + right)/2;
            // cout << mid << endl;
            if (mid*mid < x)
                left = mid+1;
            else if (mid*mid > x)
                right = mid-1;
            else
                return mid;
        }
        
        return left-1;
    }
};
