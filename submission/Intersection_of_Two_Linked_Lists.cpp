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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* initial=headB;
        if (headA == headB) return headA;
        while (headA != NULL) {
            while(headB != NULL) {
                if (headB == headA)
                    return headB;
                else
                    headB = headB->next;
            }
            headB = initial;
            headA = headA->next;
        }
        return NULL;
    }
};
