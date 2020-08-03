class Combine {
public:
    int id;
    vector<int> v1, v2, startPoint;
    
    bool equal(vector<int>& v, vector<int>& point) {
        vector<int> diff(2);
        diff[0] = point[0] - startPoint[0];
        diff[1] = point[1] - startPoint[1];
        return ((v1[0] == v[0] && v1[1] == v[1]) || (v1[0] == -v[0] && v1[1] == -v[1]
            )) && 
            ((v2[0] == diff[0] && v2[1] == diff[1]) || (v2[0] == -diff[0] && v2[1] == 
                -diff[1]));
    }
    
    double compute() {
        double x1 = v1[0] * v1[0];
        double x2 = v2[0] * v2[0];
        double y1 = v1[1] * v1[1];
        double y2 = v2[1] * v2[1];
        return sqrt((x1 + y1) * (x2 + y2));
    }
};

class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        vector<vector<vector<int>>> lines(points.size(), vector<vector<int>>(points
            .size(), vector<int>(2, 0)));
        vector<Combine> level1, level2;
        double res = DBL_MAX;
        
        for (int i=0; i<points.size(); i++) {
            for (int j=i+1; j<points.size(); j++) {
                int diffx = points[j][0] - points[i][0], diffy = points[j][1] - 
                    points[i][1];
                Combine tem;
                lines[i][j][0] = diffx;
                lines[i][j][1] = diffy;
                lines[j][i][0] = diffx;
                lines[j][i][1] = diffy;
                
                tem.startPoint = points[i];
                tem.id = j;
                tem.v1 = lines[i][j];
                level1.push_back(tem);
            }
        }
        
        for (int i=0; i<level1.size(); i++) {
            int id = level1[i].id;
            
            for (int j=0; j<lines[id].size(); j++) {
                // inner product is 0
                if (j != id && lines[id][j][0] * level1[i].v1[0] + lines[id][j][1] * 
                    level1[i].v1[1] == 0) {
                    level1[i].v2 = lines[id][j];
                    level1[i].id = j;
                    level2.push_back(level1[i]);
                }
            }
        }
        
        for (int i=0; i<level2.size(); i++) {
            int id = level2[i].id;
            
            for (int j=0; j<lines[id].size(); j++) {
                int innerProduct = lines[id][j][0] * level2[i].v2[0] + 
                    lines[id][j][1] * level2[i].v2[1];
                if (j != id && innerProduct == 0 && level2[i].equal(lines[id][j], 
                    points[j])) {
                    res = min(res, level2[i].compute());
                    if (res == 1.00000)
                        cout << "test" << endl;
                }
            }
        }
        
        return (res == DBL_MAX)? 0:res;
    }
};
// [[0,2],[0,1],[3,3],[1,0],[2,3],[1,2],[1,3]]
// [[1,2],[2,1],[1,0],[0,1]]
// [[0,1],[2,1],[1,1],[1,0],[2,0]]
// [[0,3],[1,2],[3,1],[1,3],[2,1]]
// [[3,1],[1,1],[0,1],[2,1],[3,3],[3,2],[0,2],[2,3]]
