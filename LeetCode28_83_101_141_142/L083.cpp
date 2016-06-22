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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode* temp = head;
        while(temp->next) {
            if(temp->val == temp->next->val) 
                temp->next = temp->next->next;
            else temp = temp->next;
        }
        return head;
    }
};
