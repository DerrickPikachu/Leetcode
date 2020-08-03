class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long int maxSumWithLast = 0, maxSumWithFirst = 0, maximum = INT_MIN, minimum 
            = INT_MAX, sum = 0, res = 0;
        int modulo = 1000000007;
        
        for (int i=0; i<arr.size(); i++) {
            sum += arr[i];
            
            if (maximum < sum)
                maximum = sum;
            if (minimum > sum)
                minimum = sum;
            
            res = max(sum, max(res, sum - minimum));
        }
        
        maxSumWithLast = max(sum - minimum, sum);
        maxSumWithFirst = maximum;
        if (sum > 0) {
            int arrSum = (sum * (k - 2) + maxSumWithLast + maxSumWithFirst) % modulo;
            res = (arrSum > res)? arrSum:res;
        }
        else {
            int arrSum = (maxSumWithLast + maxSumWithFirst) % modulo;
            res = (arrSum > res)? arrSum:res;
        }
        
        return res;
    }
};
