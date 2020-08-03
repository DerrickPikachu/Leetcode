class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        if (barcodes.empty())
            return vector<int>();
        vector<int> res;
        queue<int> que;
        
        res.push_back(barcodes[0]);
        
        for (int i=1; i<barcodes.size(); i++) {
            if (barcodes[i] == res.back()) {
                que.push(barcodes[i]);
            }
            else {
                res.push_back(barcodes[i]);
                if (!que.empty() && que.front() != res.back()) {
                    res.push_back(que.front());
                    que.pop();
                }
            }
        }
        int i=0;
        while(!que.empty()) {
            if (i == 0 && res[i] != que.front()) {
                res.insert(res.begin(), que.front());
                que.pop();
            }
            else if (res[i] != que.front() && res[i+1] != que.front()) {
                res.insert(res.begin() + i + 1, que.front());
                que.pop();
            }
            i = (i + 1) % (res.size() - 1);
        }
        
        return res;
    }
};
