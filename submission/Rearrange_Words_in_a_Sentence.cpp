class Solution {
public:
    string arrangeWords(string text) {
        string buffer, res;
        unordered_map<int, queue<string>> words;
        set<int> lengths;
        
        text.push_back(' ');
        for (char& c : text) {
            if (c == ' ') {
                words[buffer.size()].push(buffer);
                lengths.insert(buffer.size());
                buffer.clear();
                continue;
            } else if (c < 'a') {
                c += ('a' - 'A');
            }
            
            buffer.push_back(c);
        }
        
        for (auto& len : lengths) {
            while (!words[len].empty()) {
                string tem = words[len].front();
                words[len].pop();
                
                if (res.empty())
                    tem[0] -= 'a' - 'A';
                res += tem + " ";
            }
        }
        res.pop_back();
        return res;
    }
};
