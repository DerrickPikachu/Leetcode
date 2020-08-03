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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* i=head,*j=NULL;
        
        while (i != NULL) {
            if (i->val == val) {
                if (i == head) {
                    head = head->next;
                    delete i;
                    i = head;
                }
                else {
                    j->next = i->next;
                    delete i;
                    i = j->next;
                }
            }
            else {
                j = i;
                i = i->next;
            }
        }
        
        return head;
    }
};
