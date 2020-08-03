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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)   return true;
        ListNode* index=head;
        ListNode* index2=head;
        int len=0;
        while(index) {
            len++;
            index = index->next;
        }//count the lenth of list
        index = head;
        
        int count=0;
        while (count < (len/2-1)) {
            head = index->next;
            index->next = index->next->next;
            head->next = index2;
            count++;
            index2 = head;
        }//reverse the helf of the list
        if (len%2 == 0)
            index = index->next;
        else 
            index = index->next->next;
        
        while (index) {
            if (index2->val != index->val)
                return false;
            index = index->next;
            index2 = index2->next;
        }
        return true;
    }
};
