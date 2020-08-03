class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal(numRows);
        if (numRows == 0)   return pascal;
        int i;
        
        for (i=0;i<numRows;i++) {
            pascal[i].push_back(1);
            for (int j=1;j<=i-1;j++) {
                int plus = pascal[i-1][j-1] + pascal[i-1][j];
                pascal[i].push_back(plus);
            }
            if (i != 0) pascal[i].push_back(1);
        }
        
        return pascal;
    }
};
