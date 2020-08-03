class Solution {
private:
    int binarySearch(vector<int>& arr, int num) {
        int left = 0, right = arr.size() - 1;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            
            if (arr[mid] > num)
                right = mid - 1;
            else if (arr[mid] < num)
                left = mid + 1;
            else {
                left = mid;
                break;
            }
        }
        cout << left << endl;
        
        arr.insert(arr.begin() + left, num);
        return left;
    }
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        vector<int> distance;
        
        for (int r=0; r<R; r++) {
            for (int c=0; c<C; c++) {
                vector<int> tem(2);
                tem[0] = r;
                tem[1] = c;
                int dis = abs(r - r0) + abs(c - c0);
                int index = binarySearch(distance, dis);
                res.insert(res.begin() + index, tem);
            }
        }
        
        return res;
    }
};
