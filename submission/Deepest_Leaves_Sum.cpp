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
    int deepestLeavesSum(TreeNode* root) {
        int res = 0, levelCounter = 1;
        queue<TreeNode*> que;
        vector<TreeNode*> deepest;
        
        que.push(root);
        while (!que.empty()) {
            int next = 0;
            deepest.clear();
            
            for (int i = 0; i < levelCounter; i++) {
                TreeNode* cur = que.front();
                que.pop();
                deepest.push_back(cur);
                
                if (cur->left) {
                    que.push(cur->left);
                    next++;
                }
                if (cur->right) {
                    que.push(cur->right);
                    next++;
                }
            }
            
            levelCounter = next;
        }
        
        for (int i = 0; i < deepest.size(); i++)
            res += deepest[i]->val;
        
        return res;
    }
};
