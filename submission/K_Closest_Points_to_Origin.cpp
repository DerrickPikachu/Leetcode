class Solution {
private:
    float calDistance(int a, int b) {
        a = pow(a, 2);
        b = pow(b, 2);
        return sqrt(a + b);
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        map<float, vector<int>> mp;
        vector<vector<int>> res;
        
        for (int i=0; i<points.size(); i++) {
            float dis = calDistance(points[i][0], points[i][1]);
            
            if (!mp.count(dis)) {
                vector<int> tem;
                tem.push_back(i);
                mp[dis] = tem;
            }
            else
                mp[dis].push_back(i);
        }
        
        for (auto i : mp) {
            for (int j=0; j<i.second.size(); j++) {
                res.push_back(points[i.second[j]]);
                K--;
            }
            if (K == 0) break;
        }
        
        return res;
    }
};
