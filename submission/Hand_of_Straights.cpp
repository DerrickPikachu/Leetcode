class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if (hand.size() % W != 0)
            return false;
        map<int, int> arrange;
        
        for (int i=0; i<hand.size(); i++) {
            arrange[hand[i]]++;
        }
        
        for (auto& entry : arrange) {
            while (entry.second > 0) {
                int curNum = entry.first;
                entry.second--;

                for (int count=0; count<W-1; count++) {
                    if (!arrange.count(curNum + 1) || arrange[curNum+1] == 0)
                        return false;

                    arrange[curNum+1]--;
                    curNum++;
                }
            }
        }
        
        return true;
    }
};
