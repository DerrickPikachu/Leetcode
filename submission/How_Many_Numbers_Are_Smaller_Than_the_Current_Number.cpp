class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        map<int, int> elementCount;
        int count = 0;
        vector<int> res;
        
        for (int i : nums)
            elementCount[i]++;
        
        for (pair<int, int> entry : elementCount) {
            elementCount[entry.first] = count;
            count += entry.second;
        }
        
        for (int i : nums)
            res.push_back(elementCount[i]);
        
        return res;
    }
};
