class Solution {
public:
    string reformat(string s) {
        vector<char> letter, digit;
        string res;
        bool turn = true;
        
        for (char& c : s) {
            if (isalpha(c))
                letter.push_back(c);
            else
                digit.push_back(c);
        }
        
        turn = (letter.size() > digit.size())? true : false;
        while (!letter.empty() && !digit.empty()) {
            if (turn) {
                res.push_back(letter.back());
                letter.pop_back();
            } else {
                res.push_back(digit.back());
                digit.pop_back();
            }
            turn = !turn;
        }
        
        if (letter.empty()) {
            if (digit.size() > 1)
                return "";
            else
                res.push_back(digit.back());
        } else if (digit.empty()) {
            if (letter.size() > 1)
                return "";
            else
                res.push_back(letter.back());
        }
        
        return res;
    }
};
