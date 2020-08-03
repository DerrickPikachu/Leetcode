class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum
        ) {
        vector<vector<int>> matrix(2, vector<int>(colsum.size(), 0));
        int sum = 0, rowSum = lower + upper;
        
        for (int i=0; i<colsum.size(); i++) {
            if (colsum[i] == 2) {
                if (upper == 0 || lower == 0)
                    return vector<vector<int>>();
                upper--;
                lower--;
                matrix[0][i] = 1;
                matrix[1][i] = 1;
            }
            
            sum += colsum[i];
        }
        
        if (rowSum != sum)
            return vector<vector<int>>();
        
        for (int i=0; i<colsum.size(); i++) {
            if (colsum[i] == 1) {
                if (upper > 0) {
                    upper--;
                    matrix[0][i] = 1;
                }
                else if (lower > 0) {
                    lower--;
                    matrix[1][i] = 1;
                }
                else
                    return vector<vector<int>>();
            }
        }
        
        return matrix;
    }

