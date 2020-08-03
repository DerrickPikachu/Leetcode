class Word {
public:
    int times;
    string str;
    
    Word (int t, string s) {
        times = t;
        str = s;
    }
};

class CompareWord {
public:
    bool operator() (Word& a, Word& b) {
        if (a.times > b.times)
            return true;
        else if (a.times < b.times)
            return false;
        else {
            if (a.str < b.str)
                return true;
            else
                return false;
        }
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        priority_queue<Word, vector<Word>, CompareWord> que; 
        
        for (int i=0; i<words.size(); i++)
            mp[words[i]]++;
        
        for (auto& i : mp) {
            Word tem(i.second, i.first);
            que.push(tem);
            if (que.size() > k)
                que.pop();
        }
        
        vector<string> res(k);
        for (int i=k-1; i>=0; i--) {
            res[i] = que.top().str;
            que.pop();
        }
        
        return res;
    }
};
