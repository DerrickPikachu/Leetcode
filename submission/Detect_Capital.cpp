class Solution {
private:
    bool IfCapital (string& str) {
        bool isCap=false,isLow=false;
        
        for (int i=1;i<str.size();i++) {
            if ((str[i] - 'Z') <= 0)
                isCap = true;
            else
                isLow = true;
        }
        
        return (isCap && isLow)? false:true;
    }
    
    bool IfNonCapital (string& str) {
        bool isCap=false;
        
        for (int i=1;i<str.size();i++) {
            if ((str[i] - 'Z') <= 0)
                isCap = true;
        }
        
        return !isCap;
    }
public:
    bool detectCapitalUse(string word) {
        bool ans;
        int i;
        
        if ((word[0] - 'Z') <= 0)
            ans = IfCapital(word);
        else
            ans = IfNonCapital(word);
        
        return ans;
    }
};
