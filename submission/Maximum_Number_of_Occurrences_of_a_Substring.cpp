class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        // vector<unordered_set<char>> distinctChar(s.size());
        // vector<string> record(s.size());
        unordered_map<string, int> appearCount;
        int res = 0;
        
        for (int i=0; i <= s.size()-minSize; i++) {
            unordered_set<char> distinctChar;
            string record;
            
            for (int l=0; l<maxSize && i + l < s.size(); l++) {
                record.push_back(s[i+l]);
                
                if (!distinctChar.count(s[i+l]))
                    distinctChar.insert(s[i+l]);
                if (distinctChar.size() > maxLetters)
                    break;
                
                if (l + 1 >= minSize && l + 1 <= maxSize) {
                    appearCount[record]++;
                    res = max(res, appearCount[record]);
                }
            }
        }
        
        return res;
    }
};

