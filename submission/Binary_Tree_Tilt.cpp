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
    int findTilt(TreeNode* root) {
        if (!root)  return 0;
        int ans=0;
        DFS(root, ans);
        return ans;
    }
    int DFS(TreeNode* node, int& ans) {
        if (!node)  return 0;
        int left, right;
        
        left = DFS(node->left, ans);
        right = DFS(node->right, ans);
        // cout << left << " " << right << endl;
        ans += abs(left - right);
        
        return left + right + node->val;
    }
};
