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
    void dfs(vector<TreeNode*>& res, TreeNode* node, unordered_set<int>& _to_delete, 
        TreeNode* pre = NULL) {
        if (node) {
            if (_to_delete.count(node->val)) {
                if (pre) {
                    if (node == pre->left)
                        pre->left = NULL;
                    else
                        pre->right = NULL;
                }
                
                if (node->left) {
                    if (!_to_delete.count(node->left->val))
                        res.push_back(node->left);
                    dfs(res, node->left, _to_delete);
                }
                if (node->right) {
                    if (!_to_delete.count(node->right->val))
                        res.push_back(node->right);
                    dfs(res, node->right, _to_delete);
                }
            }
            else {
                if (node->left)
                    dfs(res, node->left, _to_delete, node);
                if (node->right)
                    dfs(res, node->right, _to_delete, node);
            }
        }
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        unordered_set<int> _to_delete;
        
        if (!root)
            return res;
        
        for (int i=0; i<to_delete.size(); i++)
            _to_delete.insert(to_delete[i]);
        
        if (!_to_delete.count(root->val))
            res.push_back(root);
        
        dfs(res, root, _to_delete);
            
        return res;
    }
};
