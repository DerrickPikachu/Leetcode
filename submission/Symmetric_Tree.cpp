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
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)  return true;
        return DFS(root->left, root->right);
    }
    
    bool DFS(TreeNode* left, TreeNode* right) {
        if (!left && !right)
            return true;
        else if ((!left && right) || (left && !right) || left->val != right->val)
            return false;
        else {
            if (!DFS(left->left, right->right))
                return false;
            if (!DFS(left->right, right->left))
                return false;
            return true;
        }
    }
};
