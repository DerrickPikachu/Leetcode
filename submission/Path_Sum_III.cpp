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
    int pathSum(TreeNode* root, int sum) {
        int path=0;
        vector<int> save;
        findPath(root, sum, path, save);
        return path;
    }
    
    void findPath(TreeNode* node, int& sum, int& path, vector<int> save) {
        if (!node)  return;
        if (node->val == sum)   path++;
        for (int i=0; i<save.size(); i++) {
            save[i] += node->val;
            path += (save[i] == sum)? 1:0;
        }
        save.push_back(node->val);
        findPath(node->left, sum, path, save);
        findPath(node->right, sum, path, save);
    }
    // int help(TreeNode* root, int sum, unordered_map<int, int>& store, int pre) {
    //     if (!root) return 0;
    //     root->val += pre;
    //     int res = (root->val == sum) + (store.count(root->val - sum) ? store[root
        ->val - sum] : 0);
    //     store[root->val]++;
    //     res += help(root->left, sum, store, root->val) + help(root->right, sum, 
        store, root->val);
    //     store[root->val]--;
    //     return res;
    // }
    //this solution is very smart
    //the map used to record the path whether it is existed
    //and while the distance between root->val and sum has occured before (use map to 
        judge)
    //the res will plus 1
    //this means that the path which has occured before is useless, and the least 
        path would be the answer.
};
