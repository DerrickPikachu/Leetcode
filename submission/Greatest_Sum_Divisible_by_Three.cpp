bool compare(int a, int b) {
    return a > b;
}

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int divisibleSum = 0;
        vector<int> remaind;
        
        for (int i=0; i<nums.size(); i++) {
            int mod = nums[i] % 3;
            if (mod == 0)
                divisibleSum += nums[i];
            else {
                remaind.push_back(nums[i]);
            }
        }
        
        sort(remaind.begin(), remaind.end(), compare);
        vector<vector<int>> r(3, vector<int>(remaind.size(), 0));
        if (remaind[0] % 3 == 1)
            r[1][0] = remaind[0];
        else
            r[2][0] = remaind[0];
        
        for (int i=1; i<remaind.size(); i++) {
            int mod = remaind[i] % 3;
            if (mod == 1) {
                r[1][i] = max(r[0][i-1] + remaind[i], r[1][i-1]);
                r[2][i] = max(r[1][i-1] + remaind[i], r[2][i-1]);
                if (r[2][i-1] != 0)
                    r[0][i] = max(r[2][i-1] + remaind[i], r[0][i-1]);
            }
            else {
                r[2][i] = max(r[0][i-1] + remaind[i], r[2][i-1]);
                r[1][i] = max(r[2][i-1] + remaind[i], r[1][i-1]);
                if (r[1][i-1] != 0)
                    r[0][i] = max(r[1][i-1] + remaind[i], r[0][i-1]);
            }
        }
        
        return divisibleSum + r[0].back();
    }
};
