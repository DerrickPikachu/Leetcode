class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> ans;
        bool checkIncrease = true;
        
        for (int i=1; i<A.size(); i++) {
            if (A[i-1] > A[i]) {
                checkIncrease = false;
                break;
            }
        }
        
        for (int i=0; i<A.size(); i++) {
            int maxIndex = 0;
            
            for (int j=1; j<A.size() - i; j++)
                maxIndex = (A[maxIndex] < A[j])? j:maxIndex;
            
            if (maxIndex != A.size() - i - 1) {
                if (maxIndex != 0) {
                    reverse(A.begin(), A.begin() + maxIndex + 1);
                    ans.push_back(maxIndex + 1);
                }
                reverse(A.begin(), A.end() - i);
                ans.push_back(A.size() - i);
            }
        }
        
        return (checkIncrease)? vector<int>():ans;
    }
};
