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
    string inorder(unordered_map<string, int>& appear, vector<TreeNode*>& res, 
        TreeNode* node) {
        if (!node)
            return "";
        string left, right, combine, val = to_string(node->val);
        
        if (node->left)
            left = inorder(appear, res, node->left);
        if (node->right)
            right = inorder(appear, res, node->right);
        
        combine = val + " " + val + "left:" + left + " " + val + "right:" + right;
        if (!appear.count(combine))
            appear[combine] = 1;
        else if (appear[combine] < 2) {
            res.push_back(node);
            appear[combine]++;
        }
        
        return combine;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> appear;
        vector<TreeNode*> res;
        inorder(appear, res, root);
        return res;
    }
};
