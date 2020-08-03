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
    int count;
    
    bool DFS(TreeNode* node, TreeNode* form) {
        count++;
        if (node == NULL) return false;
        bool check = true, isLeft = DFS(node->left, node), isRight = DFS(node->right, 
            node);
        if (!isLeft && !isRight && node->val == 0) {
            check = false;
            if (form) {
                (form->left == node)? form->left = NULL:form->right = NULL;
                delete node;
            }
        }
        
        return check;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        count = 0;
        if (!DFS(root, NULL)) {
            cout << count << endl;
            return NULL;
        }
        else return root;
    }
};
