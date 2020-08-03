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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        root = traversal(root, L, 0);
        root = traversal(root, R, 1);
        return root;
    }
    
    TreeNode* traversal(TreeNode* root, int num, bool com) {
        if (!root) return NULL;
        if (!com) {
            if (root->val < num)
                return traversal(root->right, num, com);
            else
                root->left = traversal(root->left, num, com);
        }
        else {
            if (root->val > num)
                return traversal(root->left, num, com);
            else
                root->right = traversal(root->right, num, com);
        }
        return root;
    }
};
