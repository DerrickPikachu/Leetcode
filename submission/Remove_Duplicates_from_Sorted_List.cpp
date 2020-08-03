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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL)   return head;
        ListNode* front=head,*start=head; 
        
        
        while(head != NULL) {
            if (front->val == head->val)
                head = head->next;
            else {
                front->next = head;
                front = head;
                head = head->next;
            }
        }
        // if (front->val != head->val)
        //     front->next = head;
        front->next = NULL;
        
        return start;
    }
};
