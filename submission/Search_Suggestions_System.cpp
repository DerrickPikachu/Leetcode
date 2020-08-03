class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string 
        searchWord) {
        unordered_map<string, vector<string>> table;
        vector<vector<string>> res;
        
        for (int i=0; i<products.size(); i++) {
            string tem;
            
            for (int j=0; j<products[i].size(); j++) {
                tem.push_back(products[i][j]);
                if (!table.count(tem)) {
                    table[tem].push_back(products[i]);
                }
                else {
                    for (int k=0; k<table[tem].size() + 1; k++) {
                        if (k == table[tem].size()) {
                            table[tem].push_back(products[i]);
                            break;
                        }
                        if (products[i] < table[tem][k]) {
                            table[tem].insert(table[tem].begin() + k, products[i]);
                            break;
                        }
                    }
                    if (table[tem].size() > 3)
                        table[tem].pop_back();
                }
            }
        }
        
        string word;
        for (int i=0; i<searchWord.size(); i++) {
            word.push_back(searchWord[i]);
            res.push_back(table[word]);
        }
        
        return res;
    }
};
