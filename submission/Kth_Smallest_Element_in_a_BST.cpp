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
    TreeNode* findKth(TreeNode* node, int& k) {
        TreeNode* ans = NULL;
        if (node->left) {
            ans = findKth(node->left, k);
        }
        
        if (k == 0)
            return ans;
        else if (--k == 0)
            return node;
        
        if (node->right) {
            ans = findKth(node->right, k);
            if (k == 0)
                return ans;
        }
        
        return NULL;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        return findKth(root, k)->val;
    }
};
