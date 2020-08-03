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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)  return ans;
        stack<vector<int>> output;
        queue<TreeNode*> que_node;
        vector<int> level;
        TreeNode* GetNode;
        int NextLevelNum=0,LevelNum=1;
        
        que_node.push(root);
        while (!que_node.empty()) {
            GetNode = que_node.front();
            que_node.pop();
            
            level.push_back(GetNode->val);
            LevelNum--;
            if (GetNode->left) {
                que_node.push(GetNode->left);
                NextLevelNum++;
            }
            if (GetNode->right) {
                que_node.push(GetNode->right);
                NextLevelNum++;
            }
            if (LevelNum == 0) {
                output.push(level);
                level.clear();
                LevelNum = NextLevelNum;
                NextLevelNum = 0;
            }
        }
        
        
        while (!output.empty()) {
            ans.push_back(output.top());
            output.pop();
        }
        
        return ans;
    }
};
