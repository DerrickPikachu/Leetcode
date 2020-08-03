class Solution {
public:
    int maxScore(string s) {
        vector<int> zero(s.size()), one(s.size());
        int score = 0;
        
        zero[0] = (s[0] == '0')? 1 : 0;
        one[one.size() - 1] = (s.back() == '1')? 1 : 0;
        for (int i = 1; i < s.size(); i++)
            zero[i] = (s[i] == '0')? zero[i-1] + 1 : zero[i-1];
        for (int i = s.size() - 2; i >= 0; i--)
            one[i] = (s[i] == '1')? one[i+1] + 1 : one[i+1];
        
        for (int i = 0; i < s.size() - 1; i++)
            score = max(score, zero[i] + one[i+1]);
        
        return score;
    }
};
