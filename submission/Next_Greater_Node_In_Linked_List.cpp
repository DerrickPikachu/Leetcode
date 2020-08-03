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
    int nextLarger(int num, vector<int>& nextLargerPosition, vector<int>& list, int 
        index) {
        int next = nextLargerPosition[index];
        if (next == -1)
            return -1;
        
        if (list[next] > num) {
            return next;
        }
        else {
            return nextLarger(num, nextLargerPosition, list, next);
        }
    }
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> list;
        ListNode* node = head;
        
        while (node) {
            list.push_back(node->val);
            node = node->next;
        }
        
        vector<int> res(list.size(), 0);
        vector<int> position(list.size(), -1);
        
        for (int i=list.size()-2; i>=0; i--) {
            if (list[i+1] > list[i]) {
                res[i] = list[i+1];
                position[i] = i + 1;
            }
            else {
                position[i] = nextLarger(list[i], position, list, i + 1);
                res[i] = (position[i] != -1)? list[position[i]]:0;
            }
        }
        
        return res;
    }
};
