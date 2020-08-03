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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> mp;
        vector<int> accumulate;
        ListNode* pointer = head;
        int sum = 0;
        
        while (pointer) {
            sum += pointer->val;
            
            if (accumulate.empty())
                accumulate.push_back(pointer->val);
            else
                accumulate.push_back(accumulate.back() + pointer->val);
            
            if (sum == 0) {
                //the sequence of sum = 0 is from head to this node
                head = pointer->next;
                mp.clear();
            }
            else if (mp.count(sum)) {
                //discard the sequence of sum = 0
                mp[sum]->next = pointer->next;
                
                for (int i=accumulate.size()-2; accumulate[i] != sum; i--)
                    mp.erase(accumulate[i]);
            }
            else
                mp[sum] = pointer;
            
            pointer = pointer->next;
        }
        
        return head;
    }
};
