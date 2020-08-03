/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> nextlevel;
        vector<vector<int>> ans;
        if (!root)  return ans;
        
        nextlevel.push(root);
        while (!nextlevel.empty()) {
            queue<Node*> que(nextlevel);
            vector<int> thislevel;
            while (!que.empty()) {
                Node* t = que.front();
                que.pop();
                nextlevel.pop();
                thislevel.push_back(t->val);
                for (int i=0; i<t->children.size(); i++)
                    nextlevel.push(t->children[i]);
            }
            ans.push_back(thislevel);
        }
        
        return ans;
    }
};
