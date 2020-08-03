/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
private:
    unordered_set<int> exist;
    
    void recover(TreeNode* node) {
        exist.insert(node->val);
        
        if (node->left) {
            node->left->val = node->val * 2 + 1;
            recover(node->left);
        }
        if (node->right) {
            node->right->val = node->val * 2 + 2;
            recover(node->right);
        }
    }
public:
    FindElements(TreeNode* root) {
        exist.clear();
        root->val = 0;
        recover(root);
    }
    
    bool find(int target) {
        return exist.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
