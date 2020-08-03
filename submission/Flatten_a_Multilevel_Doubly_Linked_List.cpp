/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    Node* flatten(Node* head, Node* parent = NULL, Node* endNode = NULL) {
        if (!head)  return head;
        Node* node = head;
        Node* pre = NULL;
        
        while (node) {
            Node* next, *tem = node->next;
            if (node->child)
                next = flatten(node->child, node, tem);
            else
                next = node->next;
            node->child = NULL;
            node->next = next;
            pre = node;
            node = tem;
        }
        
        if (endNode) {
            endNode->prev = pre;
            pre->next = endNode;
        }
        head->prev = parent;
        
        return head;
    }
};
