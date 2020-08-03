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
    void turnToAccendingArr(TreeNode* bst, vector<int>& arr) {
        if (!bst)
            return;
        if (bst->left)
            turnToAccendingArr(bst->left, arr);
        arr.push_back(bst->val);
        if (bst->right)
            turnToAccendingArr(bst->right, arr);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> bst1, bst2, res;
        int min1 = 0, min2 = 0;
        turnToAccendingArr(root1, bst1);
        turnToAccendingArr(root2, bst2);
        
        while (min1 < bst1.size() && min2 < bst2.size()) {
            if (bst1[min1] < bst2[min2]){
                res.push_back(bst1[min1]);
                min1++;
            }
            else {
                res.push_back(bst2[min2]);
                min2++;
            }
        }
        
        int i = (min1 == bst1.size())? min2:min1;
        vector<int>& left = (min1 == bst1.size())? bst2:bst1;
        for (; i<left.size(); i++)
            res.push_back(left[i]);
        
        return res;
    }
};
