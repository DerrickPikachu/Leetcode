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
    //dfs & dp
    pair<int, int> getMaxMoney(TreeNode* node) {
        pair<int, int> left(0, 0), right(0, 0), res(0, 0);
        int child, grandChild;
        
        if (node->left)
            left = getMaxMoney(node->left);
        if (node->right)
            right = getMaxMoney(node->right);
        child = left.first + right.first;
        grandChild = left.second + right.second;
        
        if (child > grandChild + node->val)
            res.first = child;
        else
            res.first = grandChild + node->val;
        res.second = child;
        
        return res;
    }
public:
    int rob(TreeNode* root) {
        if (!root)  return 0;
        pair<int, int> res = getMaxMoney(root);
        return res.first;
    }
};
