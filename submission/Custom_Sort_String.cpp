class Solution {
public:
    string customSortString(string S, string T) {
        unordered_set<char> st;
        unordered_map<char, int> mp;
        string unfound, res;
        
        for (int i=0; i<S.size(); i++)
            st.insert(S[i]);
        
        for (int i=0; i<T.size(); i++) {
            if (st.count(T[i]))
                mp[T[i]]++;
            else
                unfound.push_back(T[i]);
        }
        
        for (int i=0; i<S.size(); i++)
            res.insert(res.end(), mp[S[i]], S[i]);
        
        res += unfound;
        
        return res;
    }
};
