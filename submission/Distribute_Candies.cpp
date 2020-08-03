class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int lenth = candies.size(), dif=0;
        unordered_set<int> st;
        
        for (int i=0; i<lenth; i++)
            if (!st.count(candies[i])) st.insert(candies[i]);
        
        return (st.size() > lenth/2)? lenth/2:st.size();
    }
};
