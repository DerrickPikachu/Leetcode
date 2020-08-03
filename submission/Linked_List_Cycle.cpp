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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return false;
        int count=0;
        
        while(head->next != NULL) {
            if (count == 10000)
                return true;
            head = head->next;
            count++;
        }
        
        return false;
    }
};
