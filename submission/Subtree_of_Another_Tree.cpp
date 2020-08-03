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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        queue<TreeNode*> que;
        
        traversal(s, que, t->val);
        while(!que.empty()) {
            TreeNode* root = que.front();
            que.pop();
            if (compare(t, root)) return true;
        }
        
        return false;
    }
    
    void traversal(TreeNode* node, queue<TreeNode*>& que, int target) {
        if (!node) return;
        if (node->val == target)
            que.push(node);
        traversal(node->left, que, target);
        traversal(node->right, que, target);
    }
    
    bool compare(TreeNode* t, TreeNode* root) {
        if (!t && !root) return true;
        else if (t && !root || !t && root || t->val != root->val) return false;
        return (compare(t->left, root->left) && compare(t->right, root->right));
    }
};
