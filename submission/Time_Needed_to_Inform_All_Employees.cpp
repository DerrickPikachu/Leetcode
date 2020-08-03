class Solution {
private:
    int countTime(int curID, unordered_map<int, vector<int>>& subordinates, vector
        <int>& informTime) {
        if (subordinates[curID].empty())
            return informTime[curID];
        
        int maxCost = INT_MIN;
        for (int& id : subordinates[curID])
            maxCost = max(maxCost, countTime(id, subordinates, informTime));
        return informTime[curID] + maxCost;
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime
        ) {
        unordered_map<int, vector<int>> subordinates;
        for (int i = 0; i < manager.size(); i++)
            subordinates[manager[i]].push_back(i);
        return countTime(headID, subordinates, informTime);
    }
};
