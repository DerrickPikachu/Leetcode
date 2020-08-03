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
    void constructNewTree(TreeNode* t1, TreeNode* t2, TreeNode* pret1, TreeNode* 
        pret2, int direct) {
        if (t1 && t2)
            t1->val += t2->val;
        else if (!t1 && t2) {
            if (direct) {
                pret1->right = new TreeNode(t2->val);
                t1 = pret1->right;
            }
            else {
                pret1->left = new TreeNode(t2->val);
                t1 = pret1->left;
            }
        }
        else if (t1 && !t2) {
            if (direct) {
                pret2->right = new TreeNode(0);
                t2 = pret2->right;
            }
            else {
                pret2->left = new TreeNode(0);
                t2 = pret2->left;
            }
        }
        else
            return;
        constructNewTree(t1->left, t2->left, t1, t2, 0);
        constructNewTree(t1->right, t2->right, t1, t2, 1);
    }
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 && !t2)  return t1;
        else if (!t1 && t2) return t2;
        constructNewTree(t1, t2, NULL, NULL, 2);
        return t1;
    }
};
