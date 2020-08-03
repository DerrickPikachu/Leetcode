class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string word,ans;
        unordered_map<string,int> mp;
        int maxtime=0, i;
        bool isBanned = false;
        
        paragraph.push_back(' ');
        for (i=0; i<paragraph.size(); i++) {
            if (!((paragraph[i] >= 65 && paragraph[i] <= 90) || (paragraph[i] >= 97 
                && paragraph[i] <= 122))) {
                if (word.empty())   continue;
                for (int j=0; j<banned.size(); j++) {
                    if (word == banned[j]) {
                        isBanned = true;
                        break;
                    }
                }
                if (!isBanned) {
                    mp[word]++;
                    if (maxtime < mp[word]) {
                        maxtime = mp[word];
                        ans = word;
                    }
                }
                isBanned = false;
                word.clear();
            }
            else
                word.push_back(tolower(paragraph[i]));
        }
        
        
        return ans;
    }
};
