class Solution {
private:
    double solveEquation(unordered_map<string, unordered_map<string, double>>& mp,
                            unordered_map<string, unordered_map<string, double>>& 
                                inverseMp,
                            string dividend, string divider, unordered_set<string>& 
                                st) {
        if ((!mp.count(dividend) && !inverseMp.count(dividend)) || (!mp.count(divider
            ) && !inverseMp.count(divider)))
            return -1.0;
        
        if (dividend == divider && mp.count(dividend))
            return 1.0;
        else if (dividend == divider && !mp.count(dividend))
            return -1.0;
        
        if (mp[dividend].count(divider))
            return mp[dividend][divider];
        if (mp[divider].count(dividend))
            return 1.0 / mp[divider][dividend];
        
        st.insert(dividend);
        
        // when dividend as a dividend in the equation
        //i.first is the divider, i.second is the value
        if (mp.count(dividend)) {
            for (auto& i : mp[dividend]) {
                if (!st.count(i.first)) {
                    double ans = solveEquation(mp, inverseMp, i.first, divider, st);
                
                    if (ans != -1.0)
                        return i.second * ans;
                }
            }
        }
        
        //when dividend as a divider in the equation
        //i.first is the dividend, i.second is the value
        if (inverseMp.count(dividend)) {
            for (auto& i : inverseMp[dividend]) {
                if (!st.count(i.first)) {
                    double ans = solveEquation(mp, inverseMp, i.first, divider, st);

                    if (ans != -1.0)
                        return (1.0 / i.second) * ans;
                }
            }
        }
        
        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& 
        values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> mp, inverseMp;
        unordered_set<string> st;
        vector<double> res;
        
        for (int i=0; i<equations.size(); i++) {
            mp[equations[i][0]][equations[i][1]] = values[i];
            inverseMp[equations[i][1]][equations[i][0]] = values[i];
        }
        
        for (int i=0; i<queries.size(); i++) {
            res.push_back(solveEquation(mp, inverseMp, queries[i][0], queries[i][1], 
                st));
            st.clear();
        }
        
        return res;
    }
};

