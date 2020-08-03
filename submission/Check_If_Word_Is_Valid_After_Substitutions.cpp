class Solution {
public:
    bool isValid(string s) {
        if (s.empty())  return true;
        stack<char> buffer;
        
        for (int i=0; i<s.size(); i++) {
            if (s[i] == 'c') {
                if (buffer.size() < 2)
                    return false;
                char first, second;
                second = buffer.top();   buffer.pop();
                first = buffer.top();  buffer.pop();
                if (first != 'a' || second != 'b')
                    return false;
            }
            else
                buffer.push(s[i]);
        }
        
        return buffer.empty();
    }
};
