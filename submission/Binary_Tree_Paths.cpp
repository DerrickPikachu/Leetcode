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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root == NULL)   return ans;
        string st;
        DFS(root,ans,st);
        return ans;
    }
    
    void DFS(TreeNode* node,vector<string>& ans,string& st) {
        string save;
        save = change(node->val);
        st = st + save;
        // cout << st << endl;
        if (node->left) {
            st = st + "->";
            DFS(node->left,ans,st);
            st.pop_back();
            st.pop_back();
        }
        if (node->right) {
            st = st + "->";
            DFS(node->right,ans,st);
            st.pop_back();
            st.pop_back();
        }
        if (node->left == NULL && node->right == NULL)
            ans.push_back(st);
        st.erase(st.size()-save.size(),save.size());
    }
    
    string change(int num) {
        vector<char> ch;
        string st;
        if (num < 0) {
            st = st + "-";
            num = -num;
        }
        while (num != 0) {
            ch.push_back(num%10 + 48);
            num /= 10;
        }
        for (int i=ch.size()-1;i>=0;i--)
            st.push_back(ch[i]);
        cout << st << endl;
        return st;
    }
};
