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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> nextLevel;
        nextLevel.push(root);
        int level = 0, maximum = INT_MIN, res;
        
        while (!nextLevel.empty()) {
            queue<TreeNode*> thisLevel = nextLevel;
            int sum = 0;
            
            level++;
            
            while (!thisLevel.empty()) {
                TreeNode* tem = thisLevel.front();
                thisLevel.pop();
                nextLevel.pop();
                
                if (tem->left)
                    nextLevel.push(tem->left);
                if (tem->right)
                    nextLevel.push(tem->right);
                
                sum += tem->val;
            }
            
            if (sum > maximum) {
                maximum = sum;
                res = level;
            }
        }
        
        return res;
    }
};
