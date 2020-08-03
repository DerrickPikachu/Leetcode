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
    TreeNode* helpConstructFromPrePost(vector<int>& pre, vector<int>& post, int& prei
        , int& posti) {
        if (posti >= post.size() || prei >= pre.size())
            return NULL;
        
        TreeNode* node = new TreeNode(pre[prei]);
        
        if (pre[prei] != post[posti]) {
            node->left = helpConstructFromPrePost(pre, post, ++prei, posti);
            if (node->val == post[posti]) {
                posti++;
                return node;
            }
            node->right = helpConstructFromPrePost(pre, post, ++prei, posti);
        }
        posti++;
        
        return node;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if (pre.empty()) return NULL;
        int prei = 0, posti = 0;
        return helpConstructFromPrePost(pre, post, prei, posti);
    }
};
