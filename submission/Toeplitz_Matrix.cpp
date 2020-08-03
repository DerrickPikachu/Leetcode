class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row=matrix.size(),col=matrix[0].size(),r=0,c=0,i,diagonal_num;
        
        for (i=0;i<col;i++) {
            diagonal_num = matrix[r][i+c];
            r++;
            c++;
            while (r < row && (i+c) < col) {
                if (diagonal_num != matrix[r][i+c])
                    return false;
                r++;
                c++;
            }
            r=0;
            c=0;
        }
        r=0;c=0;
        for (i=1;i<row;i++) {
            diagonal_num = matrix[i+r][c];
            r++;
            c++;
            while ((i+r) < row && c < col) {
                if (diagonal_num != matrix[i+r][c])
                    return false;
                r++;
                c++;
            }
            r=0;
            c=0;
        }
        
        return true;
    }
};
