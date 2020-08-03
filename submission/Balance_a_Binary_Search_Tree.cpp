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
    vector<int> arr;
    
    void toSortedArr(TreeNode* node) {
        if (!node) return;
        toSortedArr(node->left);
        arr.push_back(node->val);
        toSortedArr(node->right);
    }
    
    TreeNode* arrToBST(int start, int end) {
        if (start > end) return NULL;
        int mid = (start + end) / 2;
        TreeNode* node = new TreeNode(arr[mid]);
        node->left = arrToBST(start, mid - 1);
        node->right = arrToBST(mid + 1, end);
        return node;
    }
    
public:
    TreeNode* balanceBST(TreeNode* root) {
        arr.clear();
        toSortedArr(root);
        return arrToBST(0, arr.size() - 1);
    }
};
