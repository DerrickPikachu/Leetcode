class Solution {
public:
    string breakPalindrome(string palindrome) {
        string res = palindrome;
        if (palindrome.size() == 1)
            return "";
        
        for (int i = 0; i < res.size(); i++) {
            if (res[i] != 'a') {
                if (!(res.size() % 2 != 0 && i == res.size() / 2)) {
                    res[i] = 'a';
                    break;
                }
            }
            else if (i == res.size() - 1)
                res[i] = 'b';
        }
        
        return res;
    }
};
