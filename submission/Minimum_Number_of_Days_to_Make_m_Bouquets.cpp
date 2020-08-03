class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (bloomDay.size() / k < m)
            return -1;
        long left = 1, right = pow(10, 9);
        
        while (left < right) {
            long mid = (left + right) / 2;
            int count = 0, _k = 0;
            
            for (int i = 0; i < bloomDay.size(); i++) {
                if (bloomDay[i] <= mid)
                    _k++;
                else
                    _k = 0;
                
                if (_k >= k) {
                    count++;
                    _k = 0;
                }
            }
            
            if (count >= m)
                right = mid;
            else
                left = mid + 1;
        }
        
        return left;
    }
};
