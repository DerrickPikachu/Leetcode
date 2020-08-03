class Solution {
private:
    bool isValid(unordered_map<char, int>& charCount, unordered_map<char, int>& 
        window) {
        bool valid = true;
        
        for (auto& count : charCount) {
            if (count.second > window[count.first]) {
                valid = false;
                break;
            }
        }
        
        return valid;
    }
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> charCount, window;
        int right = 0, left = 0, minLength = INT_MAX, targetL = 0, targetR = 0;
        bool found = false;
        string res;
        
        for (int i=0; i<t.size(); i++)
            charCount[t[i]]++;
        
        for (; right<s.size(); right++) {
            window[s[right]]++;
            
            while (isValid(charCount, window)) {
                if (right - left + 1 < minLength) {
                    found = true;
                    minLength = right - left + 1;
                    targetL = left;
                    targetR = right;
                }
                window[s[left]]--;
                left++;
            }
        }
        cout << targetL << " " << targetR << endl;
        res = (!found)? "":s.substr(targetL, minLength);
        
        return res;
    }
};
// "ADOBECODEBANC"
// "ABC"
// "A"
// "A"
// ""
// "A"
// "a"
// "aa"
