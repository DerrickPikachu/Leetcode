class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& 
        rightChild) {
        vector<int> unionFind(n, -1);
        int size = leftChild.size();
        
        for (int parent = 0; parent < size; parent++) {
            int left = leftChild[parent], right = rightChild[parent], root = parent;
            
            while (unionFind[root] != -1)
                root = unionFind[root];
            unionFind[parent] = (unionFind[parent] != -1)? root : unionFind[parent];
            
            if (left != -1) {
                if (unionFind[left] != -1 || unionFind[parent] == left)
                    return false;
                unionFind[left] = parent;
            }
            if (right != -1) {
                if (unionFind[right] != -1 || unionFind[parent] == right)
                    return false;
                unionFind[right] = parent;
            }
        }
        
        int rootCount = 0;
        for (int i = 0; i < size; i++) {
            if (unionFind[i] == -1) {
                if (rootCount)
                    return false;
                rootCount++;
            }
        }
        
        return true;
    }
};
