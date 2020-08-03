// int stoi(string str) {
//  int i,j=0,sum=0;
//  if (str.at(0) == '-')
//      j = 1;
//  for (i=j;i<str.size();i++)
//      sum += (str.at(i)-48)*pow(10,str.size()-1-i);
//  return (j == 1)? -sum:sum;
// }

class Solution {
public:
    int calPoints(vector<string>& ops) {
        int i,len,sec=0,last=0,sum=0;
        len = ops.size();
        stack<int> st;
        
        for (i=0;i<len;i++) {
            if (ops[i] == "+") {
                int k,m;
                k = st.top();
                st.pop();
                m = st.top();
                st.push(k);
                st.push(k+m);
            }
            else if (ops[i] == "D") {
                int k = st.top();
                st.push(k+k);
            }
            else if (ops[i] == "C") {
                st.pop();
            }
            else
                st.push(stoi(ops[i]));
            // cout << st.top() << endl;
        }
        len = st.size();
        for (i=0;i<len;i++) {
            sum += st.top();
            // cout << "*" << endl;
            st.pop();
        }
        
        return sum;
    }
};
