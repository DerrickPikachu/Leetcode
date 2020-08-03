class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> mods;
        vector<int> collect(k, 0);
        
        for (int& num : arr) {
            if (num < 0)
                mods.push_back((num % k + k) % k);
            else
                mods.push_back(num % k);
        }
        
        for (int& mod : mods) {
            if (collect[(k - mod) % k] == 0)
                collect[mod]++;
            else
                collect[(k - mod) % k]--;
        }
        
        for (int& check : collect) {
            if (check == 1)
                return false;
        }
        
        return true;
    }
};
