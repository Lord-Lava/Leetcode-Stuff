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
        map<ListNode*, bool> check;
        ListNode* temp = head;
        while(temp!=NULL) {
            if(check.find(temp)!=check.end()) {
                return true;
            }
            check[temp] = 1;
            temp = temp->next;
        }
        return false;
    }
};