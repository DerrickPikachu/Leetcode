class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        if (M.empty() || (M.size() == 1 && M[0].size() == 1)) return M;
        int i,row,j,column,k,sum=0,e;
        row = M.size();
        column = M[0].size();
        int direct[3]={1,0,-1};
        vector<vector<int>> save(row);
        
        if (row == 1) {
            for (i=0;i<column;i++) {
                sum = 0;
                if (i == 0) {
                    for (k=1;k<3;k++) 
                        sum += M[0][i-direct[k]];
                    save[0].push_back(sum/2);
                }
                else if (i == column-1) {
                    for (k=0;k<2;k++)
                        sum += M[0][i-direct[k]];
                    save[0].push_back(sum/2);
                }
                else {
                    for (k=0;k<3;k++)
                        sum += M[0][i-direct[k]];
                    save[0].push_back(sum/3);
                }
            }
            return save;
        }
        
        if (column == 1) {
            for (i=0;i<row;i++) {
                sum = 0;
                if (i == 0) {
                    for (k=1;k<3;k++) 
                        sum += M[i-direct[k]][0];
                    save[i].push_back(sum/2);
                }
                else if (i == row-1) {
                    for (k=0;k<2;k++)
                        sum += M[i-direct[k]][0];
                    save[i].push_back(sum/2);
                }
                else {
                    for (k=0;k<3;k++)
                        sum += M[i-direct[k]][0];
                    save[i].push_back(sum/3);
                }
            }
            return save;
        }
        
        for (i=0;i<row;i++) {
            for (j=0;j<column;j++) {
                sum = 0;
                if (i == 0) {
                    if (j == 0) {
                        for (k=1;k<3;k++)
                            for (e=1;e<3;e++)
                                sum += M[i-direct[k]][j-direct[e]];
                        save[i].push_back(sum/4);
                    }
                    else if (j == column-1) {
                        for (k=1;k<3;k++) 
                            for (e=0;e<2;e++) 
                                sum += M[i-direct[k]][j-direct[e]];
                        save[i].push_back(sum/4);
                    }
                    else {
                        for (k=1;k<3;k++)
                            for (e=0;e<3;e++)
                                sum += M[i-direct[k]][j-direct[e]];
                        save[i].push_back(sum/6);
                    }
                    continue;
                }
                else if (i == row-1) {
                    if (j == 0) {
                        for (k=0;k<2;k++)
                            for (e=1;e<3;e++)
                                sum += M[i-direct[k]][j-direct[e]];
                        save[i].push_back(sum/4);
                    }
                    else if (j == column-1) {
                        for (k=0;k<2;k++) 
                            for (e=0;e<2;e++) 
                                sum += M[i-direct[k]][j-direct[e]];
                        save[i].push_back(sum/4);
                    }
                    else {
                        for (k=0;k<2;k++)
                            for (e=0;e<3;e++)
                                sum += M[i-direct[k]][j-direct[e]];
                        save[i].push_back(sum/6);
                    }
                    continue;
                }
                else {
                    if (j == 0) {
                        for (k=0;k<3;k++) 
                            for (e=1;e<3;e++)
                                sum += M[i-direct[k]][j-direct[e]];
                        save[i].push_back(sum/6);
                    }
                    else if (j == column-1) {
                        for (k=0;k<3;k++) 
                            for (e=0;e<2;e++)
                                sum += M[i-direct[k]][j-direct[e]];
                        save[i].push_back(sum/6);
                    }
                    else {
                        for (k=0;k<3;k++) 
                            for (e=0;e<3;e++)
                                sum += M[i-direct[k]][j-direct[e]];
                        save[i].push_back(sum/9);
                    }
                }
            }
        }
        return save;
    }
};
