class Solution {
public:
    int minSteps(int n) {
        vector<int> DP(n+1), prime;
        if (n < 2) return 0;
        
        DP[0] = 0;
        DP[1] = 0;
        DP[2] = 2;
        prime.push_back(2);
        for (int i=3; i<=n; i++) {
            int pre, j=0;
            for (; j<prime.size(); j++) {
                if (i%prime[j] == 0) {
                    pre = i / prime[j];
                    DP[i] = DP[pre] + prime[j];
                    break;
                }
            }
            if (j == prime.size()) {
                DP[i] = i;
                prime.push_back(i);
            }
        }
        
        return DP[DP.size()-1];
    }
};
