/*
// Definition for a Node.
class Node {
public:
    int val;
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
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if (!root) return ans;
        preorder(root, ans);
        return ans;
    }
    
    void preorder(Node* node, vector<int>& arr) {
        if (!node) return;
        arr.push_back(node->val);
        for (int i=0; i<node->children.size(); i++)
            preorder(node->children[i], arr);
    }
};
