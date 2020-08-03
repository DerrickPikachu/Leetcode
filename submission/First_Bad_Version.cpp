// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    //nÓÛøúêóĞúËÁversion
    int firstBadVersion(int n) {
        long low,high,mid;
        
        low = 1;
        high = (long)n;
        
        while(low <= high) {
            
            mid = (low + high)/2;
            
            if (isBadVersion(mid)) 
                high = mid-1;
            else 
                low = mid+1;
        }
        
        return low;
    }
};
