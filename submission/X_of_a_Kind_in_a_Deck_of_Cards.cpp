class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> mp;
        int X = 0, mini = INT_MAX;
        vector<int> collect;
        
        for (int i=0; i<deck.size(); i++) {
            mp[deck[i]]++;
        }
        
        for (auto i = mp.begin(); i != mp.end(); i++) {
            collect.push_back(i->second);
            mini = min(mini, i->second);
        }
        
        for (int i=mini; i>=2; i--) {
            bool check = true;
            
            for (int j=0; j<collect.size(); j++) {
                if (collect[j] % i != 0) {
                    check = false;
                    break;
                }
            }
            
            if (check)
                return true;
        }
        
        return false;
    }
};
