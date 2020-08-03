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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> res;
        if (!root) {
            while(k != 0) {
                res.push_back(NULL);
                k--;
            }
            return res;
        }
        
        ListNode* iterator = root;
        int size = 0, partSize, remainder;
        
        while (iterator) {
            size++;
            iterator = iterator->next;
        }
        
        partSize = size / k;
        remainder = size % k;
        iterator = root;
        res.push_back(iterator);
        
        int thisSize;
        if (remainder > 0) {
            thisSize = partSize + 1;
            remainder--;
        }
        else
            thisSize = partSize;
        
        while (iterator) {
            ListNode* save = iterator->next;
            thisSize--;
            
            if (thisSize == 0) {
                if (save) {
                    res.push_back(save);
                    if (remainder > 0) {
                        thisSize = partSize + 1;
                        remainder--;
                    }
                    else
                        thisSize = partSize;
                }
                
                iterator->next = NULL;
            }
            
            iterator = save;
        }
        
        if (res.size() < k) {
            int tem = k - res.size();
            while(tem != 0) {
                res.push_back(NULL);
                tem--;
            }
        }
        
        return res;
    }
};
