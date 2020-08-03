class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int nextLighted = 1, res = 0;
        unordered_set<int> lighted;
        
        for (int i = 0; i < light.size(); i++) {
            lighted.insert(light[i]);
            
            while (lighted.count(nextLighted)) {
                lighted.erase(nextLighted);
                nextLighted++;
            }
            if (lighted.empty())
                res++;
        }
        
        return res;
    }
};
