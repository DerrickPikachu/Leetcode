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
    TreeNode* target, *now;
    
    bool helper(TreeNode* node, int& depth, int nowDepth = 1, bool isUnder = false) {
        if (!node->left && !node->right) {
            if (nowDepth == depth)
                target = now;
            else if (nowDepth > depth) {
                target = node;
                now = node;
                depth = nowDepth;
                isUnder = false;
            }
            return isUnder;
        }
        if (node->left) {
            isUnder = helper(node->left, depth, nowDepth+1, isUnder);
            if (!isUnder) now = node;
        }
        if (node->right) {
            if (isUnder  == false && now == node)
                helper(node->right, depth, nowDepth+1, true);
            else
                isUnder = helper(node->right, depth, nowDepth+1, isUnder);
            if (!isUnder) now = node;
        }
        
        return isUnder;
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root) return NULL;
        target = NULL;
        now = NULL;
        int depth = 0;
        helper(root, depth);
        return target;
    }
};
