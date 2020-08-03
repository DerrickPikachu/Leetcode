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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        queue<TreeNode*> thisLevel;
        thisLevel.push(root);
        
        while (!thisLevel.empty()) {
            queue<TreeNode*> nextLevel;
            int maximum = INT_MIN;
            
            while(!thisLevel.empty()) {
                TreeNode* node = thisLevel.front();
                maximum = (node->val > maximum)? node->val:maximum;
                
                if (node->left)
                    nextLevel.push(node->left);
                if (node->right)
                    nextLevel.push(node->right);
                
                thisLevel.pop();
            }
            
            thisLevel = nextLevel;
            ans.push_back(maximum);
        }
        
        return ans;
    }
};
