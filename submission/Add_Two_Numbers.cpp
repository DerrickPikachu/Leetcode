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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* resRoot;
        int carry = 0;
        
        if (l1 && !l2) {
            resRoot = new ListNode(l1->val);
            l1 = l1->next;
        } else if (!l1 && l2) {
            resRoot = new ListNode(l2->val);
            l2 = l2->next;
        } else if (l1 && l2) {
            resRoot = new ListNode((l1->val + l2->val) % 10);
            carry = (l1->val + l2->val) / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        ListNode* iter = resRoot;
        while (l1 != NULL && l2 != NULL) {
            iter->next = new ListNode((l1->val + l2->val + carry) % 10);
            carry = (l1->val + l2->val + carry) / 10;
            l1 = l1->next;
            l2 = l2->next;
            iter = iter->next;
        }
        
        ListNode* rest = (!l1)? l2 : l1;
        while (rest != NULL) {
            cout << rest->val << endl;
            iter->next = new ListNode((rest->val + carry) % 10);
            carry = (rest->val + carry) / 10;
            rest = rest->next;
            iter = iter->next;
        }
        
        if (carry)
            iter->next = new ListNode(carry);
        
        return resRoot;
    }
};
