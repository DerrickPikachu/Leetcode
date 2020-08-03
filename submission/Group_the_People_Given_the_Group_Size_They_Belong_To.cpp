class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> group;\
        vector<vector<int>> res;
        
        for (int i=0; i<groupSizes.size(); i++)
            group[groupSizes[i]].push_back(i);
        
        for (auto& it : group) {
            int size = it.first;
            
            for (int i=0; i<it.second.size() / size; i++) {
                vector<int> thisGroup(it.second.begin() + size * i,
                                      it.second.begin() + size * (i + 1));
                res.push_back(thisGroup);
            }
        }
        
        return res;
    }
};
