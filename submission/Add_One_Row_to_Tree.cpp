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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        queue<TreeNode*> thislevel;
        thislevel.push(root);
        if (d == 1) {
            TreeNode* head = new TreeNode(v);
            head->left = root;
            root = head;
        }
        else {
            for (int i=1; i<d-1; i++) {
                queue<TreeNode*> nextlevel;
                
                while(!thislevel.empty()) {
                    TreeNode* node = thislevel.front();
                    thislevel.pop();
                    if (node->left) nextlevel.push(node->left);
                    if (node->right) nextlevel.push(node->right);
                }
                thislevel = nextlevel;
            }
            while(!thislevel.empty()) {
                TreeNode* node = thislevel.front();
                thislevel.pop();
                TreeNode* left = new TreeNode(v);
                TreeNode* right = new TreeNode(v);
                left->left = node->left;
                right->right = node->right;
                node->left = left;
                node->right = right;
            }
        }
        return root;
    }
};
