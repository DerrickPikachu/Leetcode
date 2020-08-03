// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long low,high,i,mid;
        low = 1;
        high = (long)n;
        
        while (low <= high) {
            if (guess(low) == 0) return low;
            if (guess(high) == 0) return high;
            
            mid = (low + high)/2;
            //cout << guess(mid) << endl;
            if (guess(mid) > 0)
                low = mid+1;
            else if (guess(mid) < 0)
                high = mid-1;
            else
                return mid;
        }
    }
};
