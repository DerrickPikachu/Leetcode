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
    ListNode* middleNode(ListNode* head) {
        if (!head) return NULL;
        ListNode* mid, *node;
        int count=1;
        
        mid = head;
        node = head;
        while (node->next) {
            node = node->next;
            count++;
            mid = (count%2 == 0)? mid->next:mid;
        }
        
        return mid;
    }
};
