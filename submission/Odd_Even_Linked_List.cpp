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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;
        ListNode* odd, *even, *now;
        bool isOdd = false;
        
        even = NULL;
        odd = head;
        now = head->next;
        
        while (now != NULL) {
            ListNode* node = now;
            now = now->next;
            
            if (isOdd) {
                ListNode* headOfEven = odd->next;
                odd->next = node;
                node->next = headOfEven;
                odd = node;
            }
            else {
                if (even != NULL)
                    even->next = node;
                even = node;
            }
            
            isOdd = !isOdd;
        }
        
        if (even)
            even->next = NULL;
        
        return head;
    }
};
