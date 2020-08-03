class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        unordered_set<string> appeared;
        vector<vector<string>> resTable;
        map<int, unordered_map<string, int>> counter;
        
        for (auto& entry : orders) {
            counter[stoi(entry[1])][entry[2]]++;
            if (!appeared.count(entry[2]))
                appeared.insert(entry[2]);
        }
        
        vector<string> foods(appeared.begin(), appeared.end());
        sort(foods.begin(), foods.end());
        foods.insert(foods.begin(), "Table");
        resTable.push_back(foods);
        
        for (auto& entry : counter) {
            vector<string> tem(resTable[0].size());
            tem[0] = to_string(entry.first);
            for (int i = 1; i < resTable[0].size(); i++) {
                string food = resTable[0][i];
                if (entry.second.count(food))
                    tem[i] = to_string(entry.second[food]);
                else
                    tem[i] = "0";
            }
            resTable.push_back(tem);
        }
        
        return resTable;
    }
};
