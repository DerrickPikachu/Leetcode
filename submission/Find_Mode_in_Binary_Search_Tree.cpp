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
    vector<int> findMode(TreeNode* root) {
        int maxdup=0;
        unordered_map<int, int> mp;
        vector<int> ans;
        traversal(root, ans, maxdup, mp);
        return ans;
    }
    
    void traversal(TreeNode* root, vector<int>& ans, int& maxdup, unordered_map<int, 
        int>& mp) {
        if (!root) return;
        traversal(root->left, ans, maxdup, mp);
        mp[root->val]++;
        if (mp[root->val] > maxdup) {
            maxdup = mp[root->val];
            ans.clear();
            ans.push_back(root->val);
        }
        else if (mp[root->val] == maxdup)
            ans.push_back(root->val);
        traversal(root->right, ans, maxdup, mp);
    }
};
