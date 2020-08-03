class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        unordered_map<string, unordered_set<int>> favoriteList;
        int size = favoriteCompanies.size();
        vector<bitset<50000>> encoded(size);
        vector<bool> valid(size, true);
        vector<int> res;
        
        for (int i = 0; i < size; i++) {
            for (string& company : favoriteCompanies[i])
                favoriteList[company].insert(i);
        }
        
        cout << favoriteList.size() << endl;
        
        int counter = 0;
        for (auto& company : favoriteList) {
            for (int i = 0; i < size; i++) {
                if (company.second.count(i))
                    encoded[i].set(counter, 1);
            }
            counter++;
        }
        
        for (int i = 0; i < size; i++) {
            int cur = i;
            
            if (valid[cur]) {
                for (int j = i + 1; j < size; j++) {
                    bitset<50000> tem = encoded[cur] | encoded[j];
                    
                    if (encoded[cur] == tem) {
                        valid[j] = false;
                    } else if (encoded[j] == tem) {
                        valid[cur] = false;
                        cur = j;
                    }
                }
            }
        }
        
        for (int i = 0; i < size; i++) {
            if (valid[i])
                res.push_back(i);
        }
        
        return res;
    }
};
