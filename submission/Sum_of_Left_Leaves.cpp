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
    int sumOfLeftLeaves(TreeNode* root) {
        int ans=0;
        DFS(root, ans);
        return ans;
    }
    
    void DFS(TreeNode* node, int& ans) {
        //if node is null or it is a leave, return
        if (!node || (!node->left && !node->right))  return;
        //The left child is leave
        if (node->left && !node->left->left && !node->left->right) {
            ans += node->left->val;
            DFS(node->right, ans);
        }
        else {
            DFS(node->left, ans);
            DFS(node->right, ans);
        }
    }
};
