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
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode *p1=head->next, *p2, *temp;
        head->next=NULL;
        while(p1){
            p2=p1;
            p1=p1->next;
            temp=head;
            head=p2;
            p2->next=temp;
            
        }
        return head;
    }
};