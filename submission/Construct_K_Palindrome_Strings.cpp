class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.size())
            return false;
        else if (k == s.size())
            return true;
        unordered_map<char, int> counter;
        int even = 0, odd = 0;
        
        for (char& c : s)
            counter[c]++;
        
        for (auto& item : counter) {
            even += item.second / 2;
            if (item.second % 2 != 0)
                odd++;
        }
        
        return odd <= k;
    }
};
