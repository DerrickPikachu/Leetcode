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
    int minDepth(TreeNode* root) {
        if (!root)  return 0;
        int min_left=1,min_right=1;
        
        if (root->left) 
            min_left += minDepth(root->left);
        if (root->right)
            min_right += minDepth(root->right);
        
        if (!root->right)
            return min_left;
        else if (!root->left)
            return min_right;
        else
            return min(min_left,min_right);
    }
};
