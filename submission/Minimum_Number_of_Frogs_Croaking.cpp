class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        unordered_map<char, int> number;
        vector<int> counter(5, 0);
        int res = 0;
        
        number['c'] = 0;
        number['r'] = 1;
        number['o'] = 2;
        number['a'] = 3;
        number['k'] = 4;
        
        for (char& c : croakOfFrogs) {
            counter[number[c]]++;
            if (number[c] != 0)
                if (counter[number[c]] > counter[number[c] - 1])
                    return -1;
            if (c == 'k') {
                res = max(res, counter[0]);
                for (int i = 0; i < 5; i++)
                    counter[i]--;
            }
        }
        
        for (int& num : counter) {
            if (num != 0)
                return -1;
        }
        
        return res;
    }
};
