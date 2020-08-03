class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int frontmin, backmin, res = arr[0];
        vector<int> front(arr.size()), back(arr.size()), dpFront(arr.size()), dpBack
            (arr.size());
        
        dpFront[0] = front[0] = arr[0];
        dpBack[dpBack.size()-1] = back[back.size()-1] = arr.back();
        frontmin = min(0, arr[0]);
        backmin = min(0, arr.back());
        for (int i = 1, j = arr.size() - 2; i < arr.size(); i++, j--) {
            front[i] = arr[i] + front[i-1];
            back[j] = arr[j] + back[j+1];
            
            dpFront[i] = front[i] - frontmin;
            dpBack[j] = back[j] - backmin;
            
            frontmin = min(frontmin, front[i]);
            backmin = min(backmin, back[j]);
            
            res = max(dpFront[i], res);
        }
        
        for (int i = 1; i < arr.size() - 1; i++)
            res = max(res, dpFront[i-1] + dpBack[i+1]);
        
        return res;
    }
};
