/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right
     (right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root, int maxi = INT_MIN) {
        int left = 0, right = 0, nextMax, isGood;
        nextMax = (root->val >= maxi)? root->val : maxi;
        isGood = (root->val >= maxi)? 1 : 0;
        
        if (root->left)
            left = goodNodes(root->left, nextMax);
        if (root->right)
            right = goodNodes(root->right, nextMax);
        
        return left + right + isGood;
    }
};
