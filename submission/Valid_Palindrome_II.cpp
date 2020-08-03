class Solution {
public:
    bool validPalindrome(string s) {
        if (s.empty()) return true;
        int len = s.size();
        int right = len-1, left = 0;
        bool isModify = true;
        
        for (; left <= right; right--, left++) {
            if (s[right] != s[left]) {
                int tem1 = right, tem2 = left;
                for (right=right-1; left<=right; left++, right--) {
                    if (s[right] != s[left]) {
                        right = tem1;
                        left = tem2;
                        isModify = false;
                        break;
                    }
                }
                if (!isModify) {
                    for(left=left+1; left<=right; left++, right--) {
                        if (s[right] != s[left])
                            return false;
                    }
                    isModify = true;
                }
            }
        }
        
        return true;
    }
};
