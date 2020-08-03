class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.empty() && needle.empty())  return 0;
        if(needle.empty())  return 0;
        int i,len,k=-1,j=0;
        len = needle.size();
        int* fail = new int[len+1];
        failfunction(fail,len,needle);
        
        // for (i=0;i<len;i++) 
        //     cout << fail[i] << endl;
        
        for (i=0;i<haystack.size();i++) {
            while(k>-1 && needle.at(k+1) != haystack.at(i)) {
                k = fail[k]-1;
            }
            if (needle.at(k+1) == haystack.at(i))
                k++;
            if (k == len-1)
                return i-len+1;
            cout << k << endl;
        }
        return -1;
    }
    void failfunction(int* failarr,int len,string str) {
        int lenth = str.size();
        *(failarr) = 0;
        int k = -1;
        for (int i=1;i<lenth;i++) {
            while(k > -1 && str.at(k+1) != str.at(i)) {
                k = *(failarr + k) - 1;
            }
            if (str.at(k+1) == str.at(i))
                k++;
            *(failarr + i) = k + 1;
        }
    }
};
