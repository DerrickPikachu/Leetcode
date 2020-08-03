class Solution {
private:
    int frequenceCount(string str) {
        int smallest = 25, count = 0;
        
        for (int i=0; i<str.size(); i++) {
            int curChar = str[i] - 'a';
            
            if (smallest == curChar)
                count++;
            else if (curChar < smallest) {
                count = 1;
                smallest = curChar;
            }
        }
        
        return count;
    }
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) 
        {
        vector<int> res;
        vector<int> fOfWord;
        
        for (int i=0; i<words.size(); i++)
            fOfWord.push_back(frequenceCount(words[i]));
        
        for (int i=0; i<queries.size(); i++) {
            int fre = frequenceCount(queries[i]), match = 0;
            
            for(int j=0; j<fOfWord.size(); j++) {
                if (fOfWord[j] > fre)
                    match++;
            }
            
            res.push_back(match);
        }
        
        return res;
    }
};
