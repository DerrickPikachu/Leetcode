class Entry {
public:
    int r, c, val;
    
    Entry(int posr, int posc, int value) {
        r = posr;
        c = posc;
        val = value;
    }
    
    Entry() {
        r = 0;
        c = 0;
        val = 0;
    }
};

class EntryCompare {
public:
    bool operator() (Entry& a, Entry& b) {
        return a.val > b.val;
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<Entry, vector<Entry>, EntryCompare> minHeap;
        Entry startPos(0, 0, matrix[0][0]), pre;
        vector<vector<int>> arrived(matrix.size(), vector<int>(matrix.size(), 0));
        
        minHeap.push(startPos);
        
        while (k != 0) {
            pre = minHeap.top();
            minHeap.pop();
            cout << pre.val << endl;
            
            if (pre.r + 1 < matrix.size() && !arrived[pre.r+1][pre.c]) {
                minHeap.push(Entry(pre.r + 1, pre.c, matrix[pre.r+1][pre.c]));
                arrived[pre.r+1][pre.c] = 1;
            }
            if (pre.c + 1 < matrix.size() && !arrived[pre.r][pre.c+1]) {
                minHeap.push(Entry(pre.r, pre.c + 1, matrix[pre.r][pre.c+1]));
                arrived[pre.r][pre.c+1] = 1;
            }
            k--;
        }
        
        return pre.val;
    }
};
