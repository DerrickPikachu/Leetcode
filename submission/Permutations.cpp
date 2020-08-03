class Solution {
private:
    void allPossible(vector<vector<int>>& res, vector<int> preStatus, int front) {
        if (preStatus.size() - 1 == front) {
            res.push_back(preStatus);
            return;
        }
        
        for (int i=front; i<preStatus.size(); i++) {
            swap(preStatus[front], preStatus[i]);
            allPossible(res, preStatus, front + 1);
            swap(preStatus[front], preStatus[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        allPossible(res, nums, 0);
        return res;
    }
};
