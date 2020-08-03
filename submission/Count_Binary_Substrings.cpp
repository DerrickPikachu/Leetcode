class Solution {
public:
    int countBinarySubstrings(string s) {
        char now = s[0];
        int first=0,second=0,i,ans=0,temp;
        bool isChange=false;
        
        for (i=0;i<s.size();i++) {
            if (now == s[i]) {
                if (!isChange)
                    first++;
                else
                    second++;
            }
            else {
                now = s[i];
                if (!isChange)
                    isChange = true;
                else {
                    temp = second;
                    if (second >= first)
                        ans += first;
                    else
                        ans += second;
                    first = temp;
                    second = 0;
                }
                second++;
            }
        }
        if (second >= first)
            ans += first;
        else
            ans += second;
        
        return ans;
    }
};
