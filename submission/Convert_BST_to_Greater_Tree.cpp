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
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        traversal(root, sum);
        return root;
    }
    
    void traversal(TreeNode* root, int& sum) {
        if (!root) return;
        traversal(root->right, sum);
        sum += root->val;
        root->val = sum;
        traversal(root->left, sum);
    }
};
