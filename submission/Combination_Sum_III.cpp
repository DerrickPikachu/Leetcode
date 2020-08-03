class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<vector<int>>> count(n+1);
        
        for (int i=1; i<=n; i++) {
            //initiate
            if (i < 10)
                count[i].push_back(vector<int>(1, i));
            
            for (int j=0; j<count[i].size(); j++) {
                int last = count[i][j].back();
                
                for (int increase=last+1; increase + i <=n && increase < 10; increase
                    ++) {
                    int sum = increase + i;
                    
                    vector<int> tem = count[i][j];
                    tem.push_back(increase);
                    count[sum].push_back(tem);
                }
            }
        }
        
        vector<vector<int>> res;
        for (int i=0; i<count[n].size(); i++)
            if (count[n][i].size() == k)
                res.push_back(count[n][i]);
        
        return res;
    }
};
