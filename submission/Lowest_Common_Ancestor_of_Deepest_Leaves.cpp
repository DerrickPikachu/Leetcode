/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* res;
    
    int dfs(TreeNode* node, int depth, int& maxDepth) {
        int left = 0, right = 0;
        
        maxDepth = max(maxDepth, depth);
        
        if (!node->left && !node->right) {
            res = (depth == maxDepth)? node:res;
            return depth;
        }
        
        if (node->left)
            left = dfs(node->left, depth + 1, maxDepth);
        if (node->right)
            right = dfs(node->right, depth + 1, maxDepth);
        
        if (left == right && left == maxDepth)
            res = node;
        
        return max(left, right);
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root)
            return root;
        res = NULL;
        int maxDepth = 0;
        dfs(root, 1, maxDepth);
        return res;
    }
};
