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
    int getDecimalValue(ListNode* head) {
        int res = 0;
        ListNode* node = head;
        
        while (node != NULL) {
            res *= 2;
            res += node->val;
            node = node->next;
        }
        
        return res;
    }
};
