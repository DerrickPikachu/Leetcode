class Solution {
public:
    string reverseStr(string s, int k) {
        if (s.empty())  return s;
        int index=0,dif;
        string newstring;
        stack<char> reverse;
        
        while (index <= s.size()) {
            for (int i=0; i<k && (index+i) < s.size(); i++)
                reverse.push(s[index + i]);
            while (!reverse.empty()) {
                newstring.push_back(reverse.top());
                reverse.pop();
            }
            s.replace(index,newstring.size(),newstring);
            newstring.clear();
            index = index + 2*k;
        }
        return s;
    }
};
