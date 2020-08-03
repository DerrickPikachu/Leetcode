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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return vector<int>();
        vector<int> ans;
        queue<TreeNode*> thisLevel;
        
        thisLevel.push(root);
        while (!thisLevel.empty()) {
            queue<TreeNode*> next;
            while(!thisLevel.empty()) {
                TreeNode* tem = thisLevel.front();
                thisLevel.pop();
                if (thisLevel.empty()) //the last one in this level
                    ans.push_back(tem->val);
                if (tem->left) next.push(tem->left);
                if (tem->right) next.push(tem->right);
            }
            thisLevel = next;
        }
        
        return ans;
    }
};
