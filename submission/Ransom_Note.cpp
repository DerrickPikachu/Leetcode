class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        
        for (int i=0; i<magazine.size(); i++)
            mp[magazine[i]]++;
        for (int i=0; i<ransomNote.size(); i++) {
            if (!mp[ransomNote[i]])
                return false;
            else
                mp[ransomNote[i]]--;
        }
        
        return true;
    }
};
