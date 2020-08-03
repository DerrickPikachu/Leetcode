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
    int res;
    
    void findMaxDiff(TreeNode* node, int maxi, int mini) {
        res = max(res, max(abs(maxi - node->val), abs(mini - node->val)));
        int nextMax = (node->val > maxi)? node->val:maxi;
        int nextMin = (node->val < mini)? node->val:mini;
        
        if (node->left)
            findMaxDiff(node->left, nextMax, nextMin);
        if (node->right)
            findMaxDiff(node->right, nextMax, nextMin);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        res = 0;
        findMaxDiff(root, root->val, root->val);
        return res;
    }
};
