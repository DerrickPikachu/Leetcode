/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
private:
    vector<TreeNode*> cbt;
public:
    CBTInserter(TreeNode* root) {
        cbt.push_back(NULL);
        queue<TreeNode*> level;
        
        level.push(root);
        while (!level.empty()) {
            TreeNode* tem = level.front();
            level.pop();
            cbt.push_back(tem);
            if (tem->left)
                level.push(tem->left);
            if (tem->right)
                level.push(tem->right);
        }
    }
    
    int insert(int v) {
        TreeNode* newNode = new TreeNode(v);
        cbt.push_back(newNode);
        
        int lastIndex = cbt.size() - 1, parent = (cbt.size() - 1) / 2;
        if (lastIndex % 2 == 1)
            cbt[parent]->right = newNode;
        else if (lastIndex % 2 == 0)
            cbt[parent]->left = newNode;
        
        return cbt[parent]->val;
    }
    
    TreeNode* get_root() {
        return (cbt.size() < 2)? NULL:cbt[1];
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
