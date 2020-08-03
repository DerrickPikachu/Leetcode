class Solution {
public:
    string decodeString(string s) {
        stack<int> times;
        stack<string> entries;
        string num, word;
        
        for (int i=0; i<s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9')
                // number
                num.push_back(s[i]);
            else if (s[i] == '[') {
                times.push(stoi(num));
                entries.push(word);
                word = "";
                num = "";
            }
            else if (s[i] == ']') {
                string popedWord = entries.top();
                entries.pop();
                int time = times.top();
                times.pop();
                
                for (int j=0; j<time; j++)
                    popedWord += word;
                
                word = popedWord;
            }
            else
                // aphabet
                word.push_back(s[i]);
        }
        
        return word;
    }
};
