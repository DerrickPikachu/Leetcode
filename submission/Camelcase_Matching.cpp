class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        
        for (int i=0; i<queries.size(); i++) {
            string cur = queries[i];
            int p = 0;
            bool moreBiggerCase = false;
            
            for (int j=0; j<cur.size(); j++) {
                if (p < pattern.size() && pattern[p] == cur[j]) {
                    p++;
                }
                else if (cur[j] >= 'A' && cur[j] <= 'Z'){
                    moreBiggerCase = true;
                    break;
                }
            }
            
            if (p < pattern.size() || moreBiggerCase)
                res.push_back(false);
            else
                res.push_back(true);
        }
        
        return res;
    }
};
