class Solution {
public:
    int findLUSlength(string a, string b) {
        int longer,shorter;
        
        if (a.size() > b.size()) {
            longer = a.size();
            shorter = b.size();
        }
        else {
            longer = b.size();
            shorter = a.size();
        }
        if (longer == shorter) {
            for (int i=0; i<longer; i++) {
                if (a[i] != b[i])
                    return longer;
            }
            return -1;
        }
        else
            return longer;
    }
};
