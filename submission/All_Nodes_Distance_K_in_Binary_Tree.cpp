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
    bool DFS(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if (!root)
            return false;
        else path.push_back(root);
        
        if (root == target)
            return true;
        else {
            if (DFS(root->left, target, path))
                return true;
            if (DFS(root->right, target, path))
                return true;
        }
        path.pop_back();
        return false;
    }
    void BFS(TreeNode* node, TreeNode* pre, int dist, vector<int>& ans) {
        queue<TreeNode*> que;
        int nextlevel = 1;
        que.push(node);
        
        while (!que.empty() && dist >= 0) {
            int i=nextlevel;
            nextlevel = 0;
            for (; i>0; i--) {
                TreeNode* tem = que.front();
                que.pop();
                if (tem != pre) {
                    if (tem->left) {
                        que.push(tem->left);
                        nextlevel++;
                    }
                    if (tem->right) {
                        que.push(tem->right);
                        nextlevel++;
                    }
                    if (dist == 0)
                        ans.push_back(tem->val);
                }
            }
            dist--;
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<TreeNode*> path;
        DFS(root, target, path);
        vector<int> ans;
        TreeNode* pre;
        
        BFS(path[path.size()-1], NULL, k, ans);
        pre = path[path.size()-1];
        path.pop_back();
        k--;
        while (!path.empty() && k >= 0) {
            TreeNode* node = path[path.size()-1];
            // cout << node->val << endl;
            BFS(node, pre, k, ans);
            k--;
            pre = node;
            path.pop_back();
        }
        
        return ans;
    }
};
