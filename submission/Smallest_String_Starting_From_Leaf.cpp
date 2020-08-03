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
    vector<int> smallest;
    void dfs(TreeNode* node, vector<int>& tem) {
        tem.push_back(node->val);
        if (node->left)
            dfs(node->left, tem);
        if (node->right)
            dfs(node->right, tem);
        
        if (!node->left && !node->right) {
            if (smallest.empty())
                smallest = tem;
            else {
                int i = smallest.size()-1, j = tem.size()-1;
                for (; i>=0 && j>=0; i--, j--) {
                    if (smallest[i] > tem[j]) {
                        smallest = tem;
                        tem.pop_back();
                        return;
                    }
                    else if (smallest[i] < tem[j]) {
                        tem.pop_back();
                        return;
                    }
                }
                
                if (j < 0)
                    smallest = tem;
            }
        }
        
        tem.pop_back();
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        if (!root) return string();
        smallest.clear();
        vector<int> tem;
        dfs(root, tem);
        string ans;
        
        for (int i=smallest.size()-1; i>=0; i--)
            ans += 'a' + smallest[i];
        
        return ans;
    }
};
