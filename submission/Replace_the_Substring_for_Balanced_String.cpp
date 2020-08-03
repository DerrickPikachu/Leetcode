class Solution {
public:
    int balancedString(string s) {
        unordered_map<char, int> mp;
        unordered_map<char, queue<int>> inWindow;
        int needs = s.size() / 4, res = INT_MAX;
        
        for (int i=0; i<s.size(); i++)
            mp[s[i]]++;
        
        for (auto& i : mp) {
            if (i.second > needs)
                i.second = i.second - needs;
            else
                i.second = 0;
        }
        
        for (auto& i : mp) {
            cout << i.first << " " << i.second << endl;
        }
        
        for (int i=0; i<s.size(); i++) {
            if (mp[s[i]] != 0) {
                bool canSubstitute = true;
                inWindow[s[i]].push(i);
                
                if (inWindow[s[i]].size() > mp[s[i]])
                    inWindow[s[i]].pop();
                
                for (auto i : mp) {
                    if (inWindow[i.first].size() != i.second) {
                        canSubstitute = false;
                        break;
                    }
                }
                
                if (canSubstitute) {
                    queue<int> *tem;
                    int mini = INT_MAX;
                    
                    for (auto& i : inWindow) {
                        if (!i.second.empty() && mini > i.second.front()) {
                            mini = i.second.front();
                            tem = &i.second;
                        }
                    }
                    res = min(res, i - mini + 1);
                    tem->pop();
                }
                
            }
        }
        
        return (res == INT_MAX)? 0:res;
    }
};
