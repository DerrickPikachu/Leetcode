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
    bool hasPathSum(TreeNode* root, int sum, int plus=0) {
        if (!root)  return false;
        plus += root->val;
        cout << plus << endl;
        if (!root->left && !root->right) {
            return (sum == plus)? true:false;
        }
        if (root->left) {
            if (hasPathSum(root->left,sum,plus))
                return true;
        }
        if (root->right) {
            if (hasPathSum(root->right,sum,plus))
                return true;
        }
        
        return false;
    }
};
