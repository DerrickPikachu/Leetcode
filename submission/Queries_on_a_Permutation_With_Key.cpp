class Solution {
public:
        vector<int> processQueries(vector<int>& queries, int m) {
                vector<int> p(m), res;
                
                for (int i = 0; i < m; i++)
                        p[i] = i + 1;
                
                for (int& query : queries) {
                        for (int i = 0; i < p.size(); i++) {
                                if (p[i] == query) {
                                        res.push_back(i);
                                        p.erase(p.begin() + i);
                                        p.insert(p.begin(), query);
                                }
                        }
                }
                
                return res;
        }
};
