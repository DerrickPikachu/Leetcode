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
    int maxFrequent;
    int helper(unordered_map<int, int>& mp, vector<int>& ans, TreeNode* node) {
        int left = 0, right = 0, sum;
        
        if (node->left)
            left += helper(mp, ans, node->left);
        if (node->right)
            right += helper(mp, ans, node->right);
        sum = node->val + left + right;
        
        if (mp.count(sum))
            mp[sum]++;
        else
            mp[sum] = 1;
        if (maxFrequent < mp[sum]) {
            ans.clear();
            maxFrequent = mp[sum];
            ans.push_back(sum);
        }
        else if (maxFrequent == mp[sum])
            ans.push_back(sum);
        
        return sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if (!root) return vector<int>();
        unordered_map<int, int> mp;
        vector<int> ans;
        maxFrequent = 0;
        helper(mp, ans, root);
        return ans;
    }
};
