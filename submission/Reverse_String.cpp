class Solution {
public:
    string reverseString(string s) {
        int head=0,tail=s.size()-1;
        
        while (tail >= head) {
            swap(s[head],s[tail]);
            head++;
            tail--;
        }
        
        return s;
    }
};
