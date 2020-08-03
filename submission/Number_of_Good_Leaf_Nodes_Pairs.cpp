/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right
     (right) {}
 * };
 */
class Solution {
private:
    void dfs(TreeNode* node, vector<string>& paths, string path, int level = 0) {
        if (!node->left && !node->right) {
            paths.push_back(path);
        } else {
            if (node->left)
                dfs(node->left, paths, path + "0", level + 1);
            if (node->right)
                dfs(node->right, paths, path + "1", level + 1);
        }
    }
public:
    int countPairs(TreeNode* root, int distance) {
        vector<string> path;
        int res = 0;
        
        dfs(root, path, "");
        
        for (int i = 0; i < path.size(); i++) {
            for (int j = i + 1; j < path.size(); j++) {
                int  k = 0;
                for (; k < path[i].size() && k < path[j].size(); k++) {
                    if (path[i][k] != path[j][k])
                        break;
                }
                
                int idis = path[i].size() - k;
                int jdis = path[j].size() - k;
                if (idis + jdis <= distance)
                    res++;
            }
        }
        
        return res;
    }
};
