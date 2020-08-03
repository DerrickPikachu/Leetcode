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
    vector<int> postorder(Node* root) {
        vector<int> arr;
        postorder(root, arr);
        return arr;
    }
    
    void postorder(Node* node, vector<int>& arr) {
        if (!node) return;
        for (int i=0; i<node->children.size(); i++)
            postorder(node->children[i], arr);
        arr.push_back(node->val);
    }
};
