class Solution {
public:
    int numTeams(vector<int>& rating) {
        vector<int> count(rating.size(), 0);
        int res = 0;
        
        for (int i = 0; i < rating.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (rating[i] > rating[j]) {
                    res += count[j];
                    count[i]++;
                }
            }
        }
        count.clear();
        count.resize(rating.size(), 0);
        for (int i = rating.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < rating.size(); j++) {
                if (rating[i] > rating[j]) {
                    res += count[j];
                    count[i]++;
                }
            }
        }
        
        return res;
    }
};
