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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> order;
        TreeNode* node = root;
        bool isPop = false;
        
        while (node) {
            TreeNode* tem;
            if (!isPop)
                res.push_back(node->val);
            
            if (node->left) {
                order.push(node);
                tem = node->left;
                node->left = NULL;
                node = tem;
                isPop = false;
                // continue;
            }
            else if (node->right) {
                order.push(node);
                tem = node->right;
                node->right = NULL;
                node = tem;
                isPop = false;
                // continue;
            }
            else {
                if (order.empty())
                    break;
                node = order.top();
                order.pop();
                isPop = true;
            }
        }
        
        return res;
    }
};
