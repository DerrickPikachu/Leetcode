class Solution {
private:
    bool dividable(string dividend, string divider) {
        if (dividend.size() % divider.size() != 0)
            return false;
        
        int facter = dividend.size() / divider.size();
        string tem;
        
        for (int i=0; i<facter; i++)
            tem += divider;
        
        return dividend == tem;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        int size = min(str1.size(), str2.size());
        string res;
        if (str1.empty() || str2.empty())
            return res;
        
        for (int i=1; i<=size; i++) {
            string divider = str1.substr(0, i);
            if (dividable(str1, divider) && dividable(str2, divider))
                res = divider;
            
            // cout << divider << endl;
        }
        
        return res;
    }
};
