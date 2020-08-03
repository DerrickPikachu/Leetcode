class Solution {
private:
    int correspondRomanNumber(char roman) {
        switch(roman) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
        }
        return 0;
    }
public:
    int romanToInt(string s) {
        int res = 0;
        
        for (int i=0; i<s.size() - 1; i++) {
            if (correspondRomanNumber(s[i]) < correspondRomanNumber(s[i + 1]))
                res += -correspondRomanNumber(s[i]);
            else
                res += correspondRomanNumber(s[i]);
        }
        res += correspondRomanNumber(s.back());
        
        return res;
    }
};
