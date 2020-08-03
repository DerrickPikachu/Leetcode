class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int k, m;
        vector<int> res;
        
        if ((tomatoSlices - 2 * cheeseSlices) % 2 != 0)
            return res;
        else {
            k = (tomatoSlices - 2 * cheeseSlices) / 2;
            m = cheeseSlices - k;
        }
        
        if (k < 0 || m < 0)
            return res;
        
        res.push_back(k);
        res.push_back(m);
        return res;
    }
};
