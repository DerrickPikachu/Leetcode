class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        queue<int> turned;
        int maxLenth = 0, nowLenth = 0, count = K;
        
        for (int i=0; i<A.size(); i++) {
            if (A[i] == 0) {
                turned.push(i);
                
                if (count != 0) {
                    count--;
                    nowLenth += 1;
                }
                else if (turned.size() >= 2){
                    int first, second;
                    first = turned.front();
                    turned.pop();
                    nowLenth = i - first;
                }
                else {
                    turned.pop();
                    nowLenth = 0;
                }
                //turned.size() won't become zero,
                //because I push a new value in the beginning of this if section
            }
            else
                nowLenth++;
            maxLenth = max(maxLenth, nowLenth);
        }
        
        return maxLenth;
    }
};
