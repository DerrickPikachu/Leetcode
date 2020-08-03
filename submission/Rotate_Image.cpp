class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n <= 1) return;
        
        for (int i=0, j=n-1; i < n-1 && j > 0; i++, j--) {
            //step 1: save the element in the first row
            vector<int> save;
            for (int k=1; k<=j; k++)
                save.push_back(matrix[i][k]);
            
            //step 2: put the elements which in the first column into first row
            for (int r=i, c=j; r < n && c >= 0; r++, c--)
                matrix[i][c] = matrix[r][0];
            
            //step 3: pop the first elements in the other rows, and push back with 
                saved elements
            for (int k=i+1, l=0; k < n && l < save.size(); k++, l++) {
                matrix[k].erase(matrix[k].begin());
                matrix[k].insert(matrix[k].begin() + j, save[l]);
            }
        }
    }
};
