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
    int maxDepth(Node* root) {
        if (!root) return 0;
        vector<queue<Node*>> level;
        queue<Node*> t;
        
        t.push(root);
        level.push_back(t);
        for (int i=0; !level[i].empty(); i++) {
            queue<Node*> nextlevel;
            while (!level[i].empty()) {
                Node* get = level[i].front();
                level[i].pop();
                for (int j=0; j<get->children.size(); j++)
                    nextlevel.push(get->children[j]);
            }
            level.push_back(nextlevel);
        }
        
        return level.size()-1;
    }
};
