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
    int maxDepth(TreeNode* root) {
        if (!root)  return 0;
        int max_left=1,save,max_right=1;
        
        if (root->left)
            max_left += maxDepth(root->left);
        if (root->right)
            max_right += maxDepth(root->right);
        
        return (max_left > max_right)? max_left:max_right;
    }
};
