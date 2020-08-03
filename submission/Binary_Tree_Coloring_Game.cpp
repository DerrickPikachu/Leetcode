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
    void count(TreeNode* node, vector<int>& occupied, int x, bool left = false, bool 
        right = false) {
        if (x != node->val) {
            if (!left && !right)
                occupied[0]++;
            else if (left && !right)
                occupied[1]++;
            else
                occupied[2]++;
            
            if (node->left)
                count(node->left, occupied, x, left, right);
            if (node->right)
                count(node->right, occupied, x, left, right);
        }
        else {
            for (int i=0; i<occupied.size(); i++) occupied[i]++;
            if (node->left)
                count(node->left, occupied, x, true, false);
            if (node->right)
                count(node->right, occupied, x, false, true);
        }
    }
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        vector<int> occupied(3, 0);
        count(root, occupied, x);
        if (occupied[0] + occupied[1] < occupied[2] || 
            occupied[1] + occupied[2] < occupied[0] || 
            occupied[2] + occupied[0] < occupied[1])
            return true;
        return false;
    }
};
