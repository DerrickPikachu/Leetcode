class Solution {
private:
    int search(vector<int>& arr, int left, int right, int& target) {
        while (left <= right) {
            int mid = (left + right)/2;
            if (arr[mid] > target)
                right = mid - 1;
            else if (arr[mid] < target)
                left = mid + 1;
            else
                return mid;
        }
        return right;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int row = matrix.size()-1, col = matrix[0].size()-1, index=-1;
        
        while (row >= 0) {
            index = search(matrix[row], index+1, col, target);
            if (index != -1 && matrix[row][index] == target) return true;
            row--;
        }
        
        return false;
    }
};
