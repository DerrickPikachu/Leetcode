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
        stack<int> i1,i2;
        ListNode* ans=NULL,*node;
        int carry=0;
        while (l1) {
            i1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            i2.push(l2->val);
            l2 = l2->next;
        }
        
        while (!i1.empty() || !i2.empty()) {
            int num;
            if (i1.empty())
                num = i2.top() + carry;
            else if (i2.empty())
                num = i1.top() + carry;
            else
                num = i1.top() + i2.top() + carry;
            if (num >= 10) {
                num %= 10;
                carry = 1;
            }
            else
                carry = 0;
            node = new ListNode(num);
            if (ans)
                node->next = ans;
            ans = node;
            if (i1.empty())
                i2.pop();
            else if (i2.empty())
                i1.pop();
            else {
                i1.pop();
                i2.pop();
            }
        }
        if (carry == 1) {
            node = new ListNode(1);
            node->next = ans;
            ans = node;
        }
        
        return ans;
    }
};
