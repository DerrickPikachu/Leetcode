/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> inGraph;
        int conponent = 0;
        bool isConnected = false;
        ListNode* node = head;
        
        for (int i=0; i<G.size(); i++)
            inGraph.insert(G[i]);
        
        while (node) {
            if (!isConnected && inGraph.count(node->val)) {
                conponent++;
                isConnected = true;
            }
            else if (isConnected && !inGraph.count(node->val))
                isConnected = false;
            
            node = node->next;
        }
        
        return conponent;
    }
};
