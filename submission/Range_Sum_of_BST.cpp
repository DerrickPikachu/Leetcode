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
    int sumup(TreeNode* root) {
        if (!root) return 0;
        int sum = 0;
        
        sum += sumup(root->left);
        sum += sumup(root->right);
        sum += root->val;
        
        return sum;
    }
    
    int subtreeSum(TreeNode* root, int r) {
        int sum = 0;
        if (!root) return 0;
        
        if (root->val > r)
            sum += subtreeSum(root->left, r);
        else if (root->val <= r) {
            sum += sumup(root->left) + root->val;
            return sum += (root->val == r)? 0:subtreeSum(root->right, r);
        }
        
        return sum; 
    }
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        stack<TreeNode*> path;
        TreeNode* tem = root;
        int sum = 0;
        
        while (tem->val != L) {
            if (tem->val > L) {
                path.push(tem);
                tem = tem->left;
            }
            else
                tem = tem->right;
        }//The nodes in the path must be bigger than L
        path.push(tem);
        
        while (!path.empty()) {
            tem = path.top();
            path.pop();
            sum += (tem->val > R)? 0:subtreeSum(tem->right, R) + tem->val;
        }
        
        return sum;
    }
};
