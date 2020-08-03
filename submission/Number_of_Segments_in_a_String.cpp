class Solution {
public:
    int countSegments(string s) {
        int ans=0;
        s.push_back(' ');
        istringstream iss(s);
        string word;
        while (iss >> word)
            ans++;
        return ans;
    }
};
