class Solution {
public:
    bool checkRecord(string s) {
        int countA = 0, countL = 0, maxL = 0;
        
        for (int i=0; i<s.size(); i++) {
            if (s[i] == 'A') {
                countA++;
                countL = 0;
            }
            else if (s[i] == 'L') {
                countL++;
                maxL = max(maxL, countL);
            }
            else
                countL = 0;
        }
        
        return !(countA > 1 || maxL > 2);
    }
};
