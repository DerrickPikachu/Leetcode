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
private:
    void countPalindromic(TreeNode* node, int& res, unordered_set<int>& odd, 
        unordered_set<int>& even) {
        int val = node->val;
        
        if (!odd.count(val) && !even.count(val)) {
            odd.insert(val);
        } else if (!odd.count(val)) {
            odd.insert(val);
            even.erase(val);
        } else if (!even.count(val)) {
            odd.erase(val);
            even.insert(val);
        }
        
        if (node->left)
            countPalindromic(node->left, res, odd, even);
        if (node->right)
            countPalindromic(node->right, res, odd, even);
        if (!node->left && !node->right) {
            if (odd.size() <= 1)
                res++;
        }
        
        if (odd.count(val)) {
            odd.erase(val);
            even.insert(val);
        } else if (even.count(val)) {
            odd.insert(val);
            even.erase(val);
        }
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_set<int> odd, even;
        int res = 0;
        countPalindromic(root, res, odd, even);
        return res;
    }
};
