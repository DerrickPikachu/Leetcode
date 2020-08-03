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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> thisLevel;
        thisLevel.push(root);
        vector<vector<int>> ans;
        if (!root) return ans;
        int count = 1;
        
        while (count != 0) {
            int nextCount=0;
            vector<int> save;
            for (int i=0; i<count; i++) {
                TreeNode* tem = thisLevel.front();
                thisLevel.pop();
                save.push_back(tem->val);
                if (tem->left) {
                    thisLevel.push(tem->left);
                    nextCount++;
                }
                if (tem->right) {
                    thisLevel.push(tem->right);
                    nextCount++;
                }
            }
            ans.push_back(save);
            count = nextCount;
        }
        
        return ans;
    }
};
