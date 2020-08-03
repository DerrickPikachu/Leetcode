class Solution {
private:
    bool compareStronger(int a, int b, int median) {
        int strA = abs(a - median), strB = abs(b - median);
        if (strA != strB)
            return strA > strB;
        else
            return a > b;
    }
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        if (arr.size() == k)
            return arr;
        int median, front, end;
        vector<int> res;
        
        sort(arr.begin(), arr.end());
        median = arr[(arr.size() - 1) / 2];
        front = 0;
        end = arr.size() - 1;
        
        while (k != 0) {
            if (compareStronger(arr[front], arr[end], median)) {
                res.push_back(arr[front]);
                front++;
            } else {
                res.push_back(arr[end]);
                end--;
            }
            k--;
        }
        
        return res;
    }
};
