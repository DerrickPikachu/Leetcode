class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        vector<vector<int>> dp(books.size(), vector<int>(books.size())), width(books
            .size(), vector<int>(books.size()))
                            , hight(books.size(), vector<int>(books.size()));
        
        for (int i=0; i<books.size(); i++) {
            dp[i][i] = books[i][1];
            width[i][i] = books[i][0];
            hight[i][i] = books[i][1];
        }
        
        for (int l=1; l<books.size(); l++) {
            for (int i=0; i+l < books.size(); i++) {
                int j = i + l;
                
                if (width[i][j-1] + books[j][0] <= shelf_width) {
                    width[i][j] = width[i][j-1] + books[j][0];
                    if (books[j][1] > hight[i][j-1]) {
                        dp[i][j] = dp[i][j-1] + books[j][1] - hight[i][j-1];
                        hight[i][j] = books[j][1];
                    }
                    else {
                        dp[i][j] = dp[i][j-1];
                        hight[i][j] = hight[i][j-1];
                    }
                }
                else {
                    dp[i][j] = dp[i][j-1] + books[j][1];
                    width[i][j] = books[j][0];
                    hight[i][j] = books[j][1];
                }
                
                for (int k=j-1; k>i; k--) {
                    int sum = dp[i][k-1] + dp[k][j];
                    if (dp[i][j] > sum) {
                        dp[i][j] = sum;
                        width[i][j] = width[k][j];
                        hight[i][j] = hight[k][j];
                    }
                }
            }
        }
        
        return dp[0].back();
    }
};

