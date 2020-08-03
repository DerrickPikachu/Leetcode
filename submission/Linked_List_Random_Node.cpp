/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* head;
    ListNode* current;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one 
            node. */
    Solution(ListNode* head) {
        this->head = head;
        current = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int loops = rand() % 1000;
        int target;
        
        while (loops != 0) {
            loops--;
            current = current->next;
            if (current == NULL)
                current = head;
        }
        
        target = current->val;
        current = current->next;
        if (current == NULL)
            current = head;
        
        return target;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
