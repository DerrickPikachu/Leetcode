class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0, front = 0, back = height.size() - 1;
        
        for (int i=height.size() - 1; i>0; i--) {
            if (height[front] < height[back]) {
                res = max(res, i * height[front]);
                front++;
            }
            else {
                res = max(res, i * height[back]);
                back--;
            }
        }
        return res;
    }
};
