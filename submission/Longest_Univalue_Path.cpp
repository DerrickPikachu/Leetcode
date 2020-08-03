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
    int longestUnivaluePath(TreeNode* root) {
        if (!root)  return 0;
        int maximum=0;
        preorder(root, maximum, 0);
        return maximum;
    }
    int preorder(TreeNode* node, int& maximum, int prelen) {
        int len = prelen, leftlen=0, rightlen=0;
        bool left=0, right=0;
        if (node->left) {
            left = (node->val == node->left->val);
            if (left)
                leftlen = preorder(node->left, maximum, len+1);
            else
                preorder(node->left, maximum, 0);
        }
        if (node->right) {
            right = (node->val == node->right->val);
            if (right)
                rightlen = preorder(node->right, maximum, len+1);
            else
                preorder(node->right, maximum, 0);
        }
        // cout << leftlen << " " << rightlen << endl;
        if (prelen != 0)
            len = max(leftlen, rightlen);
        else {
            len = leftlen + rightlen;
            maximum = max(maximum, len);
        }
        if ((!left && !right) || (!node->left && !node->right)) {
            maximum = max(maximum, prelen);
            return prelen;
        }
        return len;
    }
};
