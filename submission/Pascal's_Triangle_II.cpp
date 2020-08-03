class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0)  return vector<int>(1,1);
        vector<int> pascal(2,1);
        int i;
        
        for (i=2;i<=rowIndex;i++) {
            pascal.push_back(1);
            for (int j=i-1;j>0;j--)
                pascal[j] = pascal[j] + pascal[j-1];
        }
        
        return pascal;
    }
};
