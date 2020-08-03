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
    vector<int> DFS(TreeNode* node, int& minimum) {
        vector<int> minimax(2, 0);
        
        if (!node->left && !node->right)
            return vector<int>(2, node->val);
        if (node->left) {
            vector<int> tem = DFS(node->left, minimum);
            minimum = min(minimum, min(node->val - node->left->val, node->val - 
                tem[1]));
            minimax[0] = tem[0];
        }
        else
            minimax[0] = node->val;
        
        if (node->right) {
            vector<int> tem = DFS(node->right, minimum);
            minimum = min(minimum, min(abs(node->val - node->right->val), tem[0] - 
                node->val));
            minimax[1] = tem[1];
        }
        else
            minimax[1] = node->val;
        
        return minimax;
    }
public:
    int minDiffInBST(TreeNode* root) {
        int minimum = INT_MAX;
        DFS(root, minimum);
        return minimum;
    }
};
