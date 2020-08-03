/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    bool findPath(ListNode* node, TreeNode* treeNode) {
        if (!node)
            return true;
        else if (treeNode->val != node->val)
            return false;
        
        if (treeNode->left && findPath(node->next, treeNode->left))
            return true;
        if (treeNode->right && findPath(node->next, treeNode->right))
            return true;
        if (!treeNode->left && !treeNode->right && !node->next)
            return true;
        return false;
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root->val == head->val) {
            if (findPath(head, root))
                return true;
        }
        
        if (root->left) {
            if (isSubPath(head, root->left))
                return true;
        }
        if (root->right) {
            if (isSubPath(head, root->right))
                return true;
        }
        
        return false;
    }
};
