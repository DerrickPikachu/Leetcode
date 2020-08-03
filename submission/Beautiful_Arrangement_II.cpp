class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        bool reversed = false;
        int front = 1, back = n, start, end, modify;
        
        ans.push_back(front);
        front++;
        for (int i=0; i<k-1; i++) {
            if (!reversed) {
                ans.push_back(back);
                back--;
            }
            else {
                ans.push_back(front);
                front++;
            }
            reversed = !reversed;
        }
        
        if (reversed) {
            start = back;
            end = front;
            modify = -1;
        }
        else {
            start = front;
            end = back;
            modify = 1;
        }
        
        for (; start != end; start += modify) {
            cout << start << " " << end << endl;
            ans.push_back(start);
        }
        
        ans.push_back(start);
        return ans;
    }
};
