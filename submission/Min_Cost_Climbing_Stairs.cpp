class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.empty()) return 0;
        if (cost.size() >= 3) {
            for (int i=2; i<cost.size(); i++)
                cost[i] = min(cost[i-1] + cost[i], cost[i-2] + cost[i]);
            return min(cost[cost.size()-1], cost[cost.size()-2]);
        }
        else
            return (cost.size() == 2)? min(cost[0], cost[1]):cost[0];
    }
};
