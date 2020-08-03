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
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> nextLevel;
        int levelCount = 1;
        
        nextLevel.push(root);
        
        for (; !nextLevel.empty(); levelCount *= 2) {
            queue<TreeNode*> thisLevel = nextLevel;
            bool isComplete = true, isfull = true;
            
            if (thisLevel.size() != levelCount)
                isfull = false;
            
            while (!thisLevel.empty()) {
                TreeNode* tem = thisLevel.front();
                thisLevel.pop();
                nextLevel.pop();
                
                if (tem->left && isComplete)
                    nextLevel.push(tem->left);
                else if (tem->left && !isComplete)
                    return false;
                else if (!tem->left)
                    isComplete = false;
                
                if (tem->right != NULL && isComplete)
                    nextLevel.push(tem->right);
                else if (tem->right && !isComplete)
                    return false;
                else if (!tem->right)
                    isComplete = false;
            }
            
            if (!isfull && !nextLevel.empty())
                return false;
        }
        
        return true;
    }
};
