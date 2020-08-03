class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<pair<int, int>> big;
        vector<int> res(T.size());
        
        res[res.size() - 1] = 0;
        big.push_back(make_pair(T[T.size() - 1], T.size() - 1));
        
        for (int i=T.size()-2; i>=0; i--) {
            for (int j=big.size()-1; j>=0; j--) {
                if (big[j].first > T[i]) {
                    res[i] = big[j].second - i;
                    big.push_back(make_pair(T[i], i));
                    break;
                }
                else
                    big.pop_back();
            }
            if (big.empty()) {
                big.push_back(make_pair(T[i], i));
                res[i] = 0;
            }
        }
        
        return res;
    }
};
