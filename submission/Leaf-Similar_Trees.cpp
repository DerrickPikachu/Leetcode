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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string str1, str2;
        dfs(root1, str1);
        dfs(root2, str2);
        return str1 == str2;
    }
    void dfs(TreeNode* node, string& str) {
        if (node) {
            if (!node->left && !node->right)
                str += to_string(node->val);
            else {
                dfs(node->left, str);
                dfs(node->right, str);
            }
        }
    }
};
