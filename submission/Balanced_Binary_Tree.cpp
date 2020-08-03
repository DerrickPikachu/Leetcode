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
    int depth=0;
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL)   return true;
        int diff,dleft=0,dright=0,NowDep=depth,AfterDep=depth;
        if (root->left) {
            depth++;
            if (!isBalanced(root->left))
                return false;
            else {
                dleft = depth - NowDep;
                AfterDep = depth;
            }
        }
        depth = NowDep;
        if (root->right) {
            depth++;
            if (!isBalanced(root->right))
                return false;
            else {
                dright = depth - NowDep;
            }
        }
        
        depth = max(depth,AfterDep);
        diff = abs(dleft - dright);
        return (diff <= 1)? true:false;
    }
    
    // int DFS(TreeNode* root,int depth=0) {
    //     int depth2 = depth;
    //     if (root->left)
    //         depth = DFS(root->left,depth+1);
    //     if (root->right)
    //         depth2 = DFS(root->right,depth2+1);
    //     return (depth > depth2)? depth:depth2;
    // }
};
