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
    int dfs(TreeNode* node, int fromParent = 0) {
        int bigger = node->val, smaller = 0;
        
        if (node->right)
            bigger += dfs(node->right, fromParent);
        node->val = bigger + fromParent;
        
        if (node->left)
            smaller = dfs(node->left, node->val);
        
        return smaller + bigger;
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        dfs(root);
        return root;
    }
};
