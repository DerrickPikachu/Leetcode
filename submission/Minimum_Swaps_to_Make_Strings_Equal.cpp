class Solution {
public:
    int minimumSwap(string s1, string s2) {
        string _s1, _s2;
        int countX = 0, countY = 0, remainder;
        
        for (int i=0; i<s1.size(); i++) {
            if (s1[i] != s2[i]) {
                if (s1[i] == 'x')
                    countX++;
                else
                    countY++;
            }
        }
        
        remainder = (countX % 2) + (countY % 2);
        if (remainder == 1)
            return -1;
        
        return countX/2 + countY/2 + remainder;
    }
};
//xyxyyx
//yxyxxy
