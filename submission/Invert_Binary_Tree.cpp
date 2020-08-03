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
    TreeNode* invertTree(TreeNode* root) {
        if (!root)  return root;
        queue<TreeNode*> order;
        
        order.push(root);
        while (!order.empty()) {
            TreeNode* tem, *now;
            now = order.front();
            order.pop();
            if (now->left)
                order.push(now->left);
            if (now->right)
                order.push(now->right);
            tem = now->left;
            now->left = now->right;
            now->right = tem;
        }
        
        return root;
    }
};
