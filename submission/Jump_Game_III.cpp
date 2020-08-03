class Solution {
private:
    bool dfs(vector<int>& arr, int pos, unordered_set<int>& arrived) {
        if (arr[pos] == 0)
            return true;
        int front = pos - arr[pos], back = pos + arr[pos];
        arrived.insert(pos);
        
        if (front >= 0 && !arrived.count(front) && dfs(arr, front, arrived))
            return true;
        if (back < arr.size() && !arrived.count(back) && dfs(arr, back, arrived))
            return true;
        
        arrived.erase(pos);
        return false;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        unordered_set<int> arrived;
        return dfs(arr, start, arrived);
    }
};
