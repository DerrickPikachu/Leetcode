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
    ListNode* swapPairs(ListNode* head) {
        bool isEven = false;
        ListNode* node = head, *preNode;
        
        while (node) {
            if (isEven) {
                swap(node->val, preNode->val);
                isEven = !isEven;
            }
            else {
                preNode = node;
                isEven = !isEven;
            }
            
            node = node->next;
        }
        
        return head;
    }
};
