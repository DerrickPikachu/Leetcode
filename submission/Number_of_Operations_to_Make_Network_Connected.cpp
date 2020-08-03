class Solution {
private:
    int findRoot(vector<int>& unionSet, int position) {
        if (unionSet[position] == -1)
            return position;
        unionSet[position] = findRoot(unionSet, unionSet[position]);
        return unionSet[position];
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> unionSet(n, -1);
        int redundant = 0, components = 0;
        
        for (int i=0; i<connections.size(); i++) {
            int root1 = findRoot(unionSet, connections[i][0]);
            int root2 = findRoot(unionSet, connections[i][1]);
            
            if (root1 == root2)
                redundant++;
            else
                unionSet[root2] = root1;
        }
        
        for (int i=0; i<n; i++) {
            if (unionSet[i] == -1)
                components++;
        }
        
        return (components - 1 > redundant)? -1:components - 1;
    }
};
