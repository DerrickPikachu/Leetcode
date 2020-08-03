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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) return NULL;
        TreeNode* root;
        root = recursive(nums, 0, nums.size());
        return root;
    }
    
    TreeNode* recursive(vector<int>& arr, int front, int tail) {
        if (front == tail) return NULL;
        int maximum = INT_MIN, maxIndex = 0, i;
        
        for (i=front; i<tail; i++) {
            if (maximum < arr[i]) {
                maximum = arr[i];
                maxIndex = i;
            }
        }
        TreeNode* node = new TreeNode(arr[maxIndex]);
        node->left = recursive(arr, front, maxIndex);
        node->right = recursive(arr, maxIndex+1, tail);
        
        return node;
    }
};
