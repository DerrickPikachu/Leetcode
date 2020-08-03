class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        if (nums.size() == 1)
            return 1;
        int left = 0, right = 1, maxValPos = 0, minValPos = 0, res = 1;
        
        for (; right < nums.size(); right++) {
            int num = nums[right];
            
            if (num > nums[maxValPos]) {
                if (num - nums[minValPos] > limit) {
                    int tem = minValPos;
                    for (int i = minValPos + 1; i < right; i++) {
                        if (num - nums[i] <= limit) {
                            if (minValPos == tem)
                                minValPos = i;
                            else
                                minValPos = (nums[minValPos] > nums[i])? i : 
                                    minValPos;
                        }
                        else
                            minValPos = tem;
                    }

                    if (minValPos == tem)
                        minValPos = right;

                    int j = minValPos - 1;
                    for (; j > left && nums[j] > nums[minValPos]; j--) {}
                    left = j + 1;
                }
                maxValPos = right;
                
            } else if (num < nums[minValPos]) {
                if (nums[maxValPos] - num > limit) {
                    int tem = maxValPos;
                    for (int i = maxValPos + 1; i < right; i++) {
                        if (nums[i] - num <= limit) {
                            if (maxValPos == tem)
                                maxValPos = i;
                            else
                                maxValPos = (nums[maxValPos] < nums[i])? i : 
                                    maxValPos;
                        }
                        else
                            maxValPos = tem;
                    }

                    if (maxValPos == tem)
                        maxValPos = right;

                    int j = maxValPos - 1;
                    for (; j > left && nums[j] < nums[maxValPos]; j--) {}
                    left = j + 1;
                }
                minValPos = right;
                
            }
            
            res = max(res, right - left + 1);
            // cout << res << " " << left << " " << right << " " << nums[maxValPos] 
                << " " << nums[minValPos] << endl;
        }
        
        return res;
    }
};
