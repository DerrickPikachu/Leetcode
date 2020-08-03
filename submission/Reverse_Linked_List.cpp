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
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        ListNode* previous=NULL,*current=head,*nextone=head->next;
        
        while(nextone) {
            current->next = previous;
            previous = current;
            current = nextone;
            nextone = nextone->next;
        }
        current->next = previous;
        head = current;
        
        return head;
    }
};
