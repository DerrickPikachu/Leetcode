class Solution {
public:
    int decide,i,time=0;
    string get;
    string answer;
    string convertToTitle(int n) {
        if (n%26 == 0) {
            get = 64 + 26;
        }
        else {
            get = 64 + n%26;
        }
        answer += get;
        while (n > 26) {
            if (n%26 == 0) {
                n = n/26 - 1;
                get = 64 + n;
            }
            else {
                n = n/26;
                if (n%26 == 0) {
                    get = 64 + 26;
                }
                else {
                    get = 64 + n%26;
                }
            }
            answer.insert(0,get);
        }
        
        return answer;
    }
};
