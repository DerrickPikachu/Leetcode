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
    string tree2str(TreeNode* t) {
        string ans;
        if (!t) return ans;
        travers(t,ans);
        return ans;
    }
    
    void travers(TreeNode* t,string& str) {
        if (!t)
            return;
        else if (!t->left && ! t->right) {
            str += to_string(t->val);
            return;
        }
        else {
            str += to_string(t->val);
            str.push_back('(');
            travers(t->left,str);
            str.push_back(')');
            if (t->right) {
                str.push_back('(');
                travers(t->right,str);
                str.push_back(')');
            }
        }
    }
};
