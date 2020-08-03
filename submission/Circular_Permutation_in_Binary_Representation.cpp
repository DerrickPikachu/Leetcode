class Solution {
private:
    vector<int> grayCodeCreater(int size) {
        if (size == 1) {
            vector<int> tem(2);
            tem[0] = 0;
            tem[1] = 1;
            return tem;
        }
        
        vector<int> grayCode = grayCodeCreater(size - 1);
        vector<int> res = grayCode;
        
        for (int i=grayCode.size() - 1; i>=0; i--)
            res.push_back(grayCode[i] + pow(2, size - 1));
        
        return res;
    }
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> grayCode = grayCodeCreater(n);
        int targetPosition;
        
        for (int i=0; i<grayCode.size(); i++) {
            if (grayCode[i] == start) {
                targetPosition = i;
                break;
            }
            
            cout << grayCode[i] << endl;
        }
        
        vector<int> res(grayCode.begin() + targetPosition, grayCode.end());
        res.insert(res.end(), grayCode.begin(), grayCode.begin() + targetPosition);
        
        return res;
    }
};
