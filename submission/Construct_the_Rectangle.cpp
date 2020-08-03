class Solution {
public:
    vector<int> constructRectangle(int area) {
        if (area == 1) return vector<int>(2, 1);
        int width = 0, helf = area / 2, dis = INT_MAX;
        
        for (int i=1; i<=helf; i++) {
            if (area % i == 0 && dis > area / i - i && area / i - i >= 0) {
                width = i;
                dis = area / i - i;
            }
        }
        vector<int> ans(2);
        ans[0] = area / width;
        ans[1] = width;
        cout << ans[0] << endl;
        return ans;
    }
};
