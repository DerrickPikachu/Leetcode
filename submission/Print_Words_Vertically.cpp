class Solution {
public:
    vector<string> printVertically(string s) {
        int maxLength = 0, wordCount = 0;
        vector<string> words(1);
        
        for (int i=0; i<s.size(); i++) {
            if (s[i] != ' ')
                words[wordCount].push_back(s[i]);
            else {
                words.push_back("");
                wordCount++;
            }
            maxLength = max((int) words[wordCount].size(), maxLength);
        }
        
        vector<string> res(maxLength, string(words.size(), ' '));
        for (int i=0; i<res.size(); i++) {
            bool isAppear = false;
            
            for (int j=words.size() - 1; j>=0; j--) {
                if (!isAppear && words[j].size() <= i)
                    res[i].pop_back();
                else if (isAppear && words[j].size() <= i)
                    res[i][j] = ' ';
                else {
                    res[i][j] = words[j][i];
                    isAppear = true;
                }
            }
        }
        
        return res;
    }
};
