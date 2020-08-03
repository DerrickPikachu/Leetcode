class Solution {
private:
    void moveRow(vector<int>& row) {
        for (int i=0; i<row.size(); i++)
            row[i] = (row[i] == 0)? 1:0;
    }
    
    void moveCol(vector<vector<int>>& col, int where) {
        for (int i=0; i<col.size(); i++)
            col[i][where] = (col[i][where] == 0)? 1:0;
    }
    
    int sumUp(vector<vector<int>>& col, int where) {
        int sum = 0;
        for (int i=0; i<col.size(); i++) {
            if (col[i][where] == 1)
                sum += pow(2, col[0].size() - 1 - where);
        }
        cout << sum << endl;
        return sum;
    }
public:
    int matrixScore(vector<vector<int>>& a) {
        if (a.empty()) return 0;
        int ans = 0, rowSize = a.size(), colSize = a[0].size();
        
        for (int i=0; i<rowSize; i++) {
            if (a[i][0] == 0)
                moveRow(a[i]);
            ans += pow(2, colSize - 1);
        }
        for (int i=1; i<colSize; i++) {
            int one = 0, zero = 0;
            for (int j=0; j<rowSize; j++) {
                if (a[j][i] == 1)
                    one++;
            }
            zero = rowSize - one;
            if (zero > one)
                moveCol(a, i);
            ans += sumUp(a, i);
            // cout << ans << endl;
        }
        
        return ans;
    }
};
