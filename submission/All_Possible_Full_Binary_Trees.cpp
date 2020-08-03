/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Tree {
public:
    TreeNode* head;
    int size;
    Tree(TreeNode* node, int num) : head(node), size(num) {}
};

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> ans;
        if (n%2 == 0) return ans;
        queue<Tree> que;
        vector<Tree> save;
        TreeNode* head = new TreeNode(0);
        if (n == 1) {
            ans.push_back(head);
            return ans;
        }
        head->left = new TreeNode(0);
        head->right = new TreeNode(0);
        Tree initial(head, 3);
        que.push(initial);
        
        while (!que.empty()) {
            Tree tem = que.front();
            que.pop();
            if (tem.size == n) {
                ans.push_back(tem.head);
                continue;
            }
            TreeNode* connectLeft, *connectRight, *both;
            connectLeft = new TreeNode(0);
            connectRight = new TreeNode(0);
            both = new TreeNode(0);
            if (tem.size + 2 <= n) {
                connectLeft->left = tem.head;
                connectLeft->right = new TreeNode(0);
                connectRight->left = new TreeNode(0);
                connectRight->right = tem.head;
                Tree leftTree(connectLeft, tem.size + 2);
                Tree rightTree(connectRight, tem.size + 2);
                que.push(leftTree);
                que.push(rightTree);
                for (int i=0; i < save.size(); i++) {
                    int num = tem.size + save[i].size + 1;
                    if (num <= n) {
                        TreeNode* newLeft = new TreeNode(0), *newRight = new TreeNode
                            (0);
                        newLeft->left = tem.head;
                        newLeft->right = save[i].head;
                        Tree getTree(newLeft, num);
                        que.push(getTree);
                        newRight->left = save[i].head;
                        newRight->right = tem.head;
                        Tree getTree2(newRight, num);
                        que.push(getTree2);
                    }
                }
            }
            if (tem.size * 2 + 1 <= n) {
                both->left = tem.head;
                both->right = tem.head;
                Tree bothTree(both, tem.size * 2 + 1);
                que.push(bothTree);
            }
            save.push_back(tem);
        }
        
        return ans;
    }
};
