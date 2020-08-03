// class Solution {
// private:
//     void FailureFunction(string& str, vector<int>& fail) {
//         for (int j=1; j<str.size(); j++) {
//             int i = fail[j-1];
//             while ((str[j] != str[i+1]) && i >= 0)
//                 i = fail[i];
//             if (str[j] == str[i+1])
//                 fail[j] = i+1;
//         }
//         // for (int j=0; j<fail.size(); j++)
//         //     cout << fail[j] << " ";
//     }
// public:
//     int repeatedStringMatch(string A, string B) {
//         vector<int> fail(B.size(), -1);
//         int time=0,j=0,i=0;
        
//         FailureFunction(B, fail);
//         // cout << endl;
//         while (j < A.size() && i < B.size()) {
//             // cout << A[j] << " " << B[i] << endl;
//             // cout << j << " " << i << endl;
//             if (A[j] == B[i]) {
//                 i++;
//                 j++;
//             }
//             else {
//                 if (i == 0)
//                     j++;
//                 else
//                     i = fail[i-1]+1;
//             }
//         }
//         // cout << i << endl;
//         if (i == 0) return -1;
//         else {
//             time++;
//             j = 0;
//         }
//         for (i,j; i<B.size(); i++,j++) {
//             if (B[i] != A[j])
//                 return -1;
//             else if (j == A.size()-1) {
//                 time++;
//                 j = -1;
//             }
//         }
//         if (j != 0) time++;
        
//         return time;
//     }
// };
class Solution {
public:
    int repeatedStringMatch(string a, string b) 
    {
        vector<int> kmp(b.size()+1);
        for (int i = 1, j = 0; i < b.size();) 
        {
            
            //printf("j%c, i%c\n",b[j],b[i]);
            if(b[j] == b[i])
            {
                kmp[i++] = ++j;
            }
            else
            {
                if(j == 0)
                    i++;
                else
                    j = kmp[j -1];
            }
        }

        for(int i : kmp)
        {
            printf("%d",i);
        }
        //printf("\n");
        for (auto i = 0, j = 0; i < a.size(); i ++, j = kmp[j-1]) 
        {
            
            while (j < b.size() && a[(i + j) % a.size()] == b[j])
            {
                // printf("match i%d j%d\n",i,j);
                ++j;
            }
            if (j == b.size()) return ceil((float)(i + j) / a.size());
            // else
                // printf("unmatch i%d j%d\n",i,j);
        }
        
        return -1;
    }
};
