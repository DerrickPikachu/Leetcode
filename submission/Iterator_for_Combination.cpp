class CombinationIterator {
private:
    stack<int> indexes;
    string characters, combin;
    int leng;
public:
    CombinationIterator(string characters, int combinationLength) {
        this->characters = characters;
        for (int i = 0; i < combinationLength; i++)
            indexes.push(i);
        leng = combinationLength;
    }
    
    string next() {
        if (combin.empty())
            return combin = characters.substr(0, leng);
        int index = indexes.top();
        indexes.pop();
        combin.pop_back();
        
        if (++index < characters.size()) {
            indexes.push(index);
            combin.push_back(characters[index]);
        }
        else {
            int last = 1, preIndex = indexes.top();
            indexes.pop();
            combin.pop_back();
            
            while (preIndex + 1 >= characters.size() - last) {
                preIndex = indexes.top();
                indexes.pop();
                combin.pop_back();
                last++;
            }
            
            while (last >= 0) {
                preIndex++;
                combin.push_back(characters[preIndex]);
                indexes.push(preIndex);
                last--;
            }
        }
        
        return combin;
    }
    
    bool hasNext() {
        return !(combin[0] == characters[characters.size() - leng]);
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
