class Solution {
private:
    int howLong(vector<int>& piles, int k) {
        int times = 0;
        
        for (int i=0; i<piles.size(); i++) {
            if (piles[i] % k != 0)
                times += piles[i] / k + 1;
            else
                times += piles[i] / k;
        }
        
        return times;
    }
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int right = 0, left = 1;
        
        for (int i=0; i<piles.size(); i++) {
            right = (right < piles[i])? piles[i]:right;
        }
        
        while (left < right) {
            int mid = (left + right)/2, times = howLong(piles, mid);
            
            if (times <= H)
                right = mid;
            else if (times > H)
                left = mid + 1;
        }
        
        return left;
    }
};
