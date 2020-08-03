class Solution {
private:
    int find(vector<vector<int>>& A, vector<vector<int>>& B) {
        int maximum = 0, size = A.size();
        vector<vector<int>> record(size, vector<int>(size, 0));
        
        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                if (A[i][j] == 1) {
                    for (int k=0; i+k<size; k++) {
                        for (int l=0; j+l<size; l++) {
                            if (B[i+k][j+l] == 1) {
                                record[k][l]++;
                                maximum = max(maximum, record[k][l]);
                                // cout << k << " " << l << endl;
                                // cout << record[k][l] << endl;
                            }
                        }
                    }
                }
            }
        }
        
        return maximum;
    }
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int res = 0;
        res = max(find(A, B), find(B, A));
        return res;
    }
};
