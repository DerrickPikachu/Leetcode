class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == 0 || n - m >= INT_MAX/2) return 0;
        else if (n == INT_MAX) return m;
        int test = m;
        for (int i=m+1; i<=n; i++)
            test = test & i;
        return test;
    }
};
