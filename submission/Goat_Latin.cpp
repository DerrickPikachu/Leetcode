class Solution {
public:
    string toGoatLatin(string S) {
        if (S.empty())  return S;
        string ans,tail,word,count_a = "a";
        bool isSpace = true;
        int i;
        
        for (i=0;i<S.size();i++) {
            if (S[i] == ' ') {
                ans += word + tail + count_a + " ";
                count_a += 'a';
                isSpace = true;
                word = "";
                tail = "";
                continue;
            }
            if (isSpace) {
                if (isVowel(S[i])) {
                    tail = "ma";
                    word += S[i];
                }
                else {
                    tail = S[i];        
                    tail += "ma";                
                }
                isSpace = false;
            }
            else
                word += S[i];
        }
        ans += word + tail + count_a;
        
        return ans;
    }
    
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c 
            == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        else
            return false;
    }
};
