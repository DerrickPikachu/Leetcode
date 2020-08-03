class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> ans;
        vector<int> large(2);
        large[0]=0;
        int i,start=-1,end=0;
        
        for (i=1;i<S.size();i++) {
            if (S.at(i) == S.at(i-1)) {
                if (start == -1)
                    start = i-1;
            }
            else {
                end = i-1;
                if ((end-start) >= 2 && start != -1) {
                    large[0] = start;
                    large[1] = end;
                    ans.push_back(large);
                }
                start = -1;
                end = 0;
            }
        }
        end = i-1;
        if ((end-start) >= 2 && start != -1) {
            large[0] = start;
            large[1] = end;
            ans.push_back(large);
        }
        
        return ans;
    }
};
        
