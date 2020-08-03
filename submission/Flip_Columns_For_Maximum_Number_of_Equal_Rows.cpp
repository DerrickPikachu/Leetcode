class Solution {
private:
    string generateKey(vector<int>& arr) {
        string key = "";
        
        if (!arr.empty()) {
            key = to_string(arr[0]);
            for (int i=1; i<arr.size(); i++)
                key += "_" + to_string(arr[i]);
        }
        
        return key;
    }
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> typeCount;
        int res = 0;
        
        for (int r=0; r<matrix.size(); r++) {
            vector<int> positionOfOne, positionOfZero;
            string keyType0, keyType1;
            
            for (int c=0; c<matrix[0].size(); c++) {
                if (!matrix[r][c])
                    positionOfZero.push_back(c);
                else
                    positionOfOne.push_back(c);
            }
            
            keyType0 = generateKey(positionOfZero);
            keyType1 = generateKey(positionOfOne);
            
            typeCount[keyType0]++;
            typeCount[keyType1]++;
        }
        
        for (auto& i : typeCount)
            res = max(res, i.second);
        
        return res;
    }
};
