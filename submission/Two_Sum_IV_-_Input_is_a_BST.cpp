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
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        unordered_set<int> st;
        if (traversal(root, st, k)) return true;
        else {
            st.erase(k/2);
            return traversal(root, st, k);
        }
    }
    
    bool traversal(TreeNode* node, unordered_set<int>& st, int& k) {
        if (!node) return false;
        if (!st.count(node->val)) {
            if (!st.count(k - node->val))
                st.insert(k - node->val);
            return traversal(node->left, st, k)? true:traversal(node->right, st, k);
        }
        else return true;
    }
};
