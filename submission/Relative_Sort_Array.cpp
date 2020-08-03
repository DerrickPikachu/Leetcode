class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        if (arr1.empty())
            return vector<int>();
        unordered_set<int> st;
        unordered_map<int, int> mp;
        vector<int> unfind, res;
        
        for (int i=0; i<arr2.size(); i++)
            st.insert(arr2[i]);
        
        for (int i=0; i<arr1.size(); i++) {
            if (st.count(arr1[i]))
                mp[arr1[i]]++;
            else
                unfind.push_back(arr1[i]);
        }
        
        sort(unfind.begin(), unfind.end());
        for (int i=0; i<arr2.size(); i++)
            res.insert(res.end(), mp[arr2[i]], arr2[i]);
        res.insert(res.end(), unfind.begin(), unfind.end());
        
        return res;
    }
};
