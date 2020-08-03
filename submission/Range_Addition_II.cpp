class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int r = m, c = n;
        
        for (int op=0; op<ops.size(); op++) {
            r = (r > ops[op][0])? ops[op][0]:r;
            c = (c > ops[op][1])? ops[op][1]:c;
        }
        
        return r * c;
    }
};
