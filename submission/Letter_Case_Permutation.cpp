class Solution {
private:
    void dfs(string& s, vector<string>& res, int index = 0) {
        
        for (int i=index; i<s.size(); i++) {
            string tem = s;
            if (isalpha(s[i])) {
                if (isupper(s[i]))
                    tem[i] = tolower(tem[i]);
                else if (islower(s[i]))
                    tem[i] = toupper(tem[i]);
                res.push_back(tem);
                dfs(tem, res, i+1);
            }
        }
    }
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        res.push_back(S);
        dfs(S, res);
        return res;
    }
};
