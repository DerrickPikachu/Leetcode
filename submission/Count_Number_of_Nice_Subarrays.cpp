class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int window = 0, res = 0, left = 1, right = 1, segment = 1;
        queue<int> distance;
        
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                if (window == 0)
                    left++;
                else if (window < k)
                    segment++;
                else if (window == k)
                    right++;
            }
            else {
                if (window < k) {
                    if (window != 0) {
                        distance.push(segment);
                        segment = 1;
                    }
                    window++;
                }
                else if (window == k) {
                    res += left * right;
                    distance.push(right);
                    left = distance.front();
                    distance.pop();
                    right = 1;
                }
            }
        }
        
        if (window == k)
            res += left * right;
        
        cout << left << " " << right << endl;
        
        return res;
    }
};
