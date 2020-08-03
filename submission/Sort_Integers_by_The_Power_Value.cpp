bool compare(pair<int, int>& a, pair<int, int>& b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> powers;
        
        for (int i = lo; i <= hi; i++) {
            int tem = i, counter = 0;
            
            while (tem != 1) {
                counter++;
                if (tem % 2 == 0)
                    tem /= 2;
                else
                    tem = tem * 3 + 1;
            }
            
            powers.push_back(pair<int, int>(counter, i));
        }
        
        sort(powers.begin(), powers.end(), compare);
        return powers[k - 1].second;
    }
};
