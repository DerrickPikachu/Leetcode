class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int count = 1, vertical = 0, horizontal = 1, r = 0, c = 0, decrease = 0;
        bool circle = false;
        
        while (count <= n * n) {
            matrix[r][c] = count;
            
            if (c + horizontal >= n - decrease) {
                horizontal = 0;
                vertical = 1;
            }
            else if (r + vertical >= n - decrease) {
                horizontal = -1;
                vertical = 0;
            }
            else if (c + horizontal < 0 + decrease && !circle) {
                horizontal = 0;
                vertical = -1;
                decrease++;
                circle = true;
            }
            else if (r + vertical < 0 + decrease) {
                horizontal = 1;
                vertical = 0;
                circle = false;
            }
            
            r += vertical;
            c += horizontal;
            count++;
        }
        
        return matrix;
    }
};
