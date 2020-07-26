class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int distance = -1;
        
        for (int& val : left)
            distance = max(distance, val);
        for (int& val : right)
            distance = max(distance, n - val);
        
        return distance;
    }
};
