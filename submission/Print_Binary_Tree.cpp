/*
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
    int height(TreeNode* node) {
        return height(node, 1);
    }
    
    int height(TreeNode* node, int h) {
        int left = h, right = h;
        
        if (node->left)
            left = height(node->left, h+1);
        if (node->right)
            right = height(node->right, h+1);
        
        return max(left, right);
    }
    
    int calculateLength(int level) {
        return pow(2, level) - 1;
    }
    
    void setTree(vector<vector<string>>& res, TreeNode* node, int l, int s, int e) {
        int mid = (s + e)/2;
        res[l][mid] = to_string(node->val);
        
        if (node->left)
            setTree(res, node->left, l + 1, s, mid - 1);
        if (node->right)
            setTree(res, node->right, l + 1, mid + 1, e);
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int level, length;
        level = height(root);
        length = calculateLength(level);

        vector<vector<string>> res(level, vector<string>(length));
        
        setTree(res, root, 0, 0, length - 1);
        return res;
    }
};
