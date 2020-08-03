class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        int res = 0;
        
        for (int i=0; i<indices.size(); i++) {
            int r = indices[i][0], c = indices[i][1];
            
            for (int ci=0; ci<m; ci++)
                matrix[r][ci]++;
            for (int ri=0; ri<n; ri++)
                matrix[ri][c]++;
        }
        
        for (int r=0; r<n; r++) {
            for (int c=0; c<m; c++) {
                if (matrix[r][c] % 2 != 0)
                    res++;
            }
        }
        
        return res;
    }
};
