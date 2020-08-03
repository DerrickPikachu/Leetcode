class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if (grid[0].size() < 3 || grid.size() < 3)  return 0;
        int row_sum[3], col_sum[3], ans=0, diagonal[2];
        bool check=true;
        
        for (int i=0; i+2<grid.size(); i++) {
            for (int j=0; j+2<grid[0].size(); j++) {
                for (int k=i; k<=i+2; k++)
                    for (int l=j; l<=j+2; l++)
                        if (grid[k][l] < 1 || grid[k][l] > 9) check = false;
                row_sum[0] = grid[i][j] + grid[i][j+1] + grid[i][j+2];
                row_sum[1] = grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2];
                row_sum[2] = grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];
                col_sum[0] = grid[i][j] + grid[i+1][j] + grid[i+2][j];
                col_sum[1] = grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1];
                col_sum[2] = grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2];
                diagonal[0] = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
                diagonal[1] = grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j];
                if (row_sum[0] == row_sum[1] && row_sum[1] == row_sum[2] && 
                    col_sum[0] == col_sum[1] && col_sum[1] == col_sum[2]
                    && row_sum[0] == col_sum[0] && diagonal[0] == diagonal[1] && 
                        diagonal[0] == row_sum[0] && check)
                    ans++;
                check = true;
            }
        }
        
        return ans;
    }
};
