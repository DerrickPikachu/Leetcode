class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        unordered_map<char, pair<int, int>> interval;
        vector<string> res;
        int left = 0;
        vector<int> endIndex;
        unordered_set<char> ispoped;
        
        for (int i = 0; i < s.size(); i++) {
            if (!interval.count(s[i])) {
                interval[s[i]] = pair<int, int>(i, i);
            } else {
                interval[s[i]].second = i;
            }
        }
        
        for (int i = 0; i < s.size(); i++) {
            if (interval[s[i]].first >= left) {
                if (!endIndex.empty() && endIndex.back() == i) {
                    int start = interval[s[i]].first, end = i;
                    int earliest = start;
                    bool valid = true;
                    
                    for (int j = start + 1; j < end; j++)
                        earliest = min(earliest, interval[s[j]].first);
                    
                    int tem = earliest;
                    do {
                        earliest = tem;
                        for (int j = tem; j < start; j++) {
                            if (interval[s[j]].second > i) {
                                valid = false;
                                break;
                            } else if (interval[s[j]].first < tem)
                                tem = interval[s[j]].first;
                        }
                        start = earliest;
                    } while (tem != earliest && valid);
                    
                    if (valid) {
                        res.push_back(s.substr(earliest, i - earliest + 1));
                        left = i + 1;
                        endIndex.clear();
                        ispoped.clear();
                    } else {
                        endIndex.pop_back();
                    }
                } else if (interval[s[i]].first == interval[s[i]].second) {
                    res.push_back(s.substr(i, 1));
                    left = i + 1;
                    endIndex.clear();
                    ispoped.clear();
                } else {
                    while (!endIndex.empty() && endIndex.back() < interval[s[i]]
                        .second) {
                        ispoped.insert(s[endIndex.back()]);
                        endIndex.pop_back();
                    }
                    if (endIndex.empty() ||
                        (endIndex.back() != interval[s[i]].second && interval[s[i]]
                            .second != i && !ispoped.count(s[i])))
                        endIndex.push_back(interval[s[i]].second);
                }
            } else {
                left = i + 1;
                endIndex.clear();
                ispoped.clear();
            }
        }
        
        return res;
    }
};
