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
    int diameterOfBinaryTree(TreeNode* root) {
        int max=0;
        DFS(root, max);
        return max;
    }
    
    int DFS(TreeNode* node, int& num) {
        int left,right;
        if (!node)
            return 0;
        left = DFS(node->left, num);
        right = DFS(node->right, num);
        if (num < (left+right))
            num = (left + right);
        left = max(left+1, right+1);
        return left;
    }
};
