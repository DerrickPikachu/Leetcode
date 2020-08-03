/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    void insert(int num, TreeNode* node) {
        if (num > node->val) {
            if (node->right)
                insert(num, node->right);
            else
                node->right = new TreeNode(num);
        }
        else {
            if (node->left)
                insert(num, node->left);
            else
                node->left = new TreeNode(num);
        }
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return string();
        queue<TreeNode*> que;
        string str = "";
        
        que.push(root);
        while(!que.empty()) {
            TreeNode* cur = que.front();
            que.pop();
            
            if (cur->left)
                que.push(cur->left);
            if (cur->right)
                que.push(cur->right);
            
            str += to_string(cur->val) + " ";
        }
        
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") return NULL;
        
        istringstream divide(data);
        string token;
        vector<int> nums;
        TreeNode* root = NULL;
        
        while (getline(divide, token, ' '))
            nums.push_back(stoi(token));
        
        root = new TreeNode(nums[0]);
        
        for (int i=1; i<nums.size(); i++)
            insert(nums[i], root);
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
