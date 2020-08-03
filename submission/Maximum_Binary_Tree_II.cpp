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
    void search(TreeNode* pre, TreeNode* node, int val) {
        if (val < node->val) {
            if (!node->right) {
                TreeNode* newNode = new TreeNode(val);
                node->right = newNode;
            }
            else
                search(node, node->right, val);
        }
        else {
            TreeNode* newNode = new TreeNode(val);
            newNode->left = node;
            pre->right = newNode;
        }
    }
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (!root) {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        if (root->val < val) {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        search(NULL, root, val);
        return root;
    }
};
