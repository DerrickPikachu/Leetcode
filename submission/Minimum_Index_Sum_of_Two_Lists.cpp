class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mp;
        int mini = INT_MAX;
        vector<string> res;
        
        for (int i=0; i<list1.size(); i++)
            mp[list1[i]] = i;
        
        for (int i=0; i<list2.size(); i++) {
            int sum;
            
            if (mp.count(list2[i])) {
                sum = i + mp[list2[i]];
                
                if (sum < mini) {
                    mini = sum;
                    res.clear();
                    res.push_back(list2[i]);
                }
                else if (sum == mini) {
                    res.push_back(list2[i]);
                }
            }
        }
        
        return res;
    }
};
