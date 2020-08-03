/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
private:
    unordered_set<string> appeared;
    
    void dfs(CustomFunction& func, int z, vector<vector<int>>& res, int x, int y) {
        string key = to_string(x) + "_" + to_string(y);
        appeared.insert(key);
        if (func.f(x, y) < z) {
            key = to_string(x + 1) + "_" + to_string(y);
            if (!appeared.count(key)) {
                dfs(func, z, res, x + 1, y);
            }
            
            key = to_string(x) + "_" + to_string(y + 1);
            if (!appeared.count(key)) {
                dfs(func, z, res, x, y + 1);
            }
        }
        else if (func.f(x, y) == z) {
            vector<int> tem(2);
            tem[0] = x;
            tem[1] = y;
            res.push_back(tem);
        }
    }
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        appeared.clear();
        vector<vector<int>> res;
        dfs(customfunction, z, res, 1, 1);
        return res;
    }
};
