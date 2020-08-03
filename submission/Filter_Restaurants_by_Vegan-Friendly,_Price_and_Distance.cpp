bool compare(vector<int>& restaurantA, vector<int>& restaurantB) {
    if (restaurantA[1] > restaurantB[1])
        return true;
    else if (restaurantA[1] < restaurantB[1])
        return false;
    else {
        if (restaurantA[0] > restaurantB[0])
            return true;
        else
            return false;
    }
}

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly
        , int maxPrice, int maxDistance) {
        sort(restaurants.begin(), restaurants.end(), compare);
        vector<int> filtered;
        
        for (int i=0; i<restaurants.size(); i++) {
            if ((veganFriendly && !restaurants[i][2]) || restaurants[i][3] > maxPrice 
                || restaurants[i][4] > maxDistance)
                continue;
            filtered.push_back(restaurants[i][0]);
        }
        
        return filtered;
    }
};
