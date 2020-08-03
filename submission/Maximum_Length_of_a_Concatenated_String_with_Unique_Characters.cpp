class Solution {
private:
    vector<int> checkValid(string str) {
        vector<int> st(26, 0);
        
        for (int s=0; s<str.size(); s++) {
            if (!st[str[s]-'a'])
                st[str[s]-'a']++;
            else {
                st.clear();
                break;
            }
        }
        
        return st;
    }
public:
    int maxLength(vector<string>& arr) {
        vector<vector<int>> possible(1, vector<int>(1, 0));
        vector<vector<vector<int>>> record(1, vector<vector<int>>(1, vector<int>(26, 
            0)));
        int res = 0;
        
        for (int i=0; i<arr.size(); i++) {
            vector<int> newRecord = checkValid(arr[i]);
            
            if (!newRecord.empty()) {
                for (int leng=possible.size()-1; leng>=0; leng--) {
                    for (int item=0; item<possible[leng].size(); item++) {
                        vector<int> _record = record[leng][item];
                        int s = 0;
                        
                        for (; s<arr[i].size(); s++) {
                            if (!_record[arr[i][s]-'a'])
                                _record[arr[i][s]-'a']++;
                            else
                                break;
                        }
                        
                        if (s == arr[i].size()) {
                            if (leng + 1 == possible.size()) {
                                possible.push_back(vector<int>(1, 
                                    possible[leng][item] + arr[i].size()));
                                record.push_back(vector<vector<int>>(1, _record));
                            }
                            else {
                                possible[leng+1].push_back(possible[leng][item] + 
                                    arr[i].size());
                                record[leng+1].push_back(_record);
                            }
                            res = (possible[leng][item] + arr[i].size() > res)? 
                                possible[leng][item] + arr[i].size():res;
                        }
                    }
                }
                
                
            }
        }
        
        return res;
    }
};
