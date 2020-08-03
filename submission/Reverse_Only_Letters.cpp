class Solution {
public:
    string reverseOnlyLetters(string S) {
        queue<char> que;
        
        for (int i=0; i<S.size(); i++) {
            if (isalpha(S[i]))
                que.push(S[i]);
        }
        
        for (int i=S.size()-1; i>=0; i--) {
            if (isalpha(S[i])) {
                S[i] = que.front();
                que.pop();
            }
        }
        
        return S;
    }
};
