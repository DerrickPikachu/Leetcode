class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int countOne = 0, countZero = 0;
        
        for (int i=0; i<chips.size(); i++) {
            if (chips[i] % 2 == 0)
                countZero++;
            else
                countOne++;
        }
        
        return min(countOne, countZero);
    }
};
