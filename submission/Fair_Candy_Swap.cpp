class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        vector<int> bigger, smaller, res;
        unordered_set<int> st;
        int Asum = 0, Bsum = 0, differ;
        
        for (int i=0; i<A.size(); i++)
            Asum += A[i];
        for (int i=0; i<B.size(); i++)
            Bsum += B[i];
        
        if (Asum > Bsum) {
            bigger.assign(A.begin(), A.end());
            smaller.assign(B.begin(), B.end());
            differ = (Asum - Bsum)/2;
        }
        else if (Bsum > Asum) {
            bigger.assign(B.begin(), B.end());
            smaller.assign(A.begin(), A.end());
            differ = (Bsum - Asum)/2;
        }
        
        for (int i=0; i<smaller.size(); i++)
            st.insert(smaller[i]);

        for (int i=0; i<bigger.size(); i++) {
            if (st.count(bigger[i] - differ)) {
                if (Asum > Bsum) {
                    res.push_back(bigger[i]);
                    res.push_back(bigger[i] - differ);
                    break;
                } else {
                    res.push_back(bigger[i] - differ);
                    res.push_back(bigger[i]);
                    break;
                }
            }
        }
        
        return res;
    }
};
