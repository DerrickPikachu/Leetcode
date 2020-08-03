/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> st;
    
    void setStack(TreeNode* node) {
        st.push(node);
        while (node->left) {
            node = node->left;
            st.push(node);
        }
    }
public:
    BSTIterator(TreeNode* root) {
        if (root)
            setStack(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* res = st.top();
        st.pop();
        
        if (res->right) {
            setStack(res->right);
        }
        
        return res->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
