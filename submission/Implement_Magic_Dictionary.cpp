class MagicDictionary {
private:
    unordered_map<int, vector<string>*> dictionary;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        dictionary.clear();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (int i=0; i<dict.size(); i++) {
            int length = dict[i].size();
            if (!dictionary.count(length)) {
                dictionary[length] = new vector<string>;
            }
            dictionary[length]->push_back(dict[i]);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after 
        modifying exactly one character */
    bool search(string word) {
        int length = word.size();
        if (!dictionary.count(length))
            return false;
        vector<string> dict = *dictionary[length];
        
        for (int i=0; i<dict.size(); i++) {
            bool check = true, ishere = false;
            
            for (int j=0; j<length; j++) {
                if (dict[i][j] != word[j]) {
                    if (check)
                        check = false;
                    else
                        break;
                }
                if (j == length-1)
                    ishere = true;
            }
            
            if (ishere && !check)
                return true;
        }
        
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */
