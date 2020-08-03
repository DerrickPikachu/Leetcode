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
    int distribute(TreeNode* node, int& ans) {
        if (!node)
            return 0;
        
        int left = distribute(node->left, ans);
        int right = distribute(node->right, ans);
        
        ans += abs(left) + abs(right);
        
        return node->val + left + right - 1;
    }

public:
    int distributeCoins(TreeNode* root) {
        int ans = 0, coin = 0;
        distribute(root, ans);
        return abs(ans);
    }
};
