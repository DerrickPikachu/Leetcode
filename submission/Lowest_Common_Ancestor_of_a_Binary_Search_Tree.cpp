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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_p, path_q;
        unordered_set<int> st;
        int size;
        TreeNode* ans;
        
        search(root, p, path_p);
        search(root, q, path_q);
        size = (path_p.size() > path_q.size())? path_q.size():path_p.size();
        for (int i=0; i < size && path_p[i] == path_q[i]; i++)
            ans = path_p[i];
        return ans;
    }
    
    void search(TreeNode* root, TreeNode* goal, vector<TreeNode*>& path) {
        path.push_back(root);
        if (goal->val > root->val) search(root->right, goal, path);
        else if (goal->val < root->val) search(root->left, goal, path);
        else return;
    }
};
