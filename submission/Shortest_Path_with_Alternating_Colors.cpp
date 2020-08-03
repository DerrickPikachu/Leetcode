class Solution {
private:
    class PathRecord {
    public:
        int node;
        int color;
        //1 = red, 0 = blue, -1 = all
        
        PathRecord(int n, int c) {
            node = n;
            color = c;
        }
    };
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, 
        vector<vector<int>>& blue_edges) {
        unordered_map<int, vector<int>> redE;
        unordered_map<int, vector<int>> blueE;
        unordered_set<int> arrivedR, arrivedB;
        queue<PathRecord> nextlevel;
        vector<int> res(n, -1);
        int length = 0;
        
        //initialize
        for (int i=0; i<red_edges.size(); i++)
            redE[red_edges[i][0]].push_back(red_edges[i][1]);
        for (int i=0; i<blue_edges.size(); i++)
            blueE[blue_edges[i][0]].push_back(blue_edges[i][1]);
        nextlevel.push(PathRecord(0, -1));
        res[0] = 0;
        arrivedR.insert(0);
        arrivedB.insert(0);
        
        while (!nextlevel.empty()) {
            queue<PathRecord> level = nextlevel;
            length++;
            
            while (!level.empty()) {
                PathRecord tem = level.front();
                int node = tem.node;
                level.pop();
                nextlevel.pop();
                
                if (tem.color == 0 || tem.color == -1) {
                    //need red edge
                    for (int i=0; i<redE[node].size(); i++) {
                        if (arrivedR.count(redE[node][i])) continue;
                        nextlevel.push(PathRecord(redE[node][i], 1));
                        cout << "from:" << node << " red:" << redE[node][i] << endl
                            ;
                        arrivedR.insert(redE[node][i]);
                        
                        if (res[redE[node][i]] == -1) {
                            res[redE[node][i]] = length;
                        }
                    }
                }
                if (tem.color == 1 || tem.color == -1){
                    //blue
                    for (int i=0; i<blueE[node].size(); i++) {
                        if (arrivedB.count(blueE[node][i])) continue;
                        nextlevel.push(PathRecord(blueE[node][i], 0));
                        cout << "from:" << node << " blue:" << blueE[node][i] << 
                            endl;
                        arrivedB.insert(blueE[node][i]);

                        if (res[blueE[node][i]] == -1) {
                            res[blueE[node][i]] = length;
                        }
                    }
                }
            }
        }
        
        return res;

