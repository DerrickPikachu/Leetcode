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
    int findBottomLeftValue(TreeNode* root) {
        int maxlevel=0, leftmost;
        dfs(root, 1, maxlevel, leftmost);
        return leftmost;
    }
    
    void dfs(TreeNode* node, int level, int& maxlevel, int& leftmost) {
        if (!node) return;
        if (level > maxlevel) {
            maxlevel++;
            leftmost = node->val;
        }
        dfs(node->left, level+1, maxlevel, leftmost);
        dfs(node->right, level+1, maxlevel, leftmost);
    }
};
