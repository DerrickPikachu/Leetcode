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
    int findSecondMinimumValue(TreeNode* root) {
        int min = root->val;
        return FindSecondMin(root, min, -1);
    }
    
    int FindSecondMin(TreeNode* node, int& min, int secmin) {
        if (!node)  return secmin;
        if (node->val != min)   return node->val;
        else {
            int left, right;
            left = FindSecondMin(node->left, min, secmin);
            right = FindSecondMin(node->right, min, secmin);
            if (left != -1 && right != -1)
                secmin = (left > right)? right:left;
            else if (left != -1 && right == -1)
                secmin = left;
            else if (left == -1 && right != -1)
                secmin = right;
        }
        return secmin;
    }
};
