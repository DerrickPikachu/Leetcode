class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int 
        newColor) {
        static int x[4] = {0,1,0,-1},y[4] = {-1,0,1,0};
        if (image.empty() || image[sr][sc] == newColor) return image;
        int r,c,save;
        
        save = image[sr][sc];
        image[sr][sc] = newColor;
        for (int i=0;i<4;i++) {
            r = sr + y[i];
            c = sc + x[i];
            if (r < 0 || c < 0 || r >= image.size() || c >= image[0].size())
                continue;
            else if (save == image[r][c])
                floodFill(image,r,c,newColor);
        }
        
        return image;
    }
};
