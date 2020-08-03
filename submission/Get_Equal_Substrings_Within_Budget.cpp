class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int maxLength = 0, windowSum = 0;
        queue<int> inSum;
        
        for (int i=0; i<s.size(); i++) {
            int diff = abs(s[i] - t[i]);
            
            windowSum = windowSum + diff;
            inSum.push(diff);
            
            while (windowSum > maxCost) {
                windowSum -= inSum.front();
                inSum.pop();
            }
            
            maxLength = max(maxLength, (int)inSum.size());
        }
        
        return maxLength;
    }
};
