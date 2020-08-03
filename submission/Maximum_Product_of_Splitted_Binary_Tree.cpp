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
    static const long int mod = pow(10, 9) + 7;
    
    int firstPass(TreeNode* node) {
        int left = 0, right = 0;
        
        if (node->left)
            left = firstPass(node->left);
        if (node->right)
            right = firstPass(node->right);
        
        node->val = node->val + left + right;
        return node->val;
    }
    
    void secondPass(TreeNode* node, long int& res, long int total) {
        res = max(res, node->val * (total - node->val));
        if (node->left)
            secondPass(node->left, res, total);
        if (node->right)
            secondPass(node->right, res, total);
    }
public:
    int maxProduct(TreeNode* root) {
        long int total = firstPass(root), res = 0;
        secondPass(root, res, total);
        return res % mod;
    }
};
