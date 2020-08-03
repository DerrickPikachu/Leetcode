class Solution {
public:
    vector<vector<int>> combine(int n, int k, int start = 1) {
        vector<vector<int>> res;
        
        for (int i=start; i<=n-k+1; i++) {
            int firstOne = i;
            if (k > 1) {
                vector<vector<int>> tem = combine(n, k - 1, i + 1);
                
                for (int j=0; j<tem.size(); j++) {
                    tem[j].insert(tem[j].begin(), firstOne);
                    res.push_back(tem[j]);
                }
            }
            else
                res.push_back(vector<int>(1, firstOne));
        }
        
        return res;
    }
};
