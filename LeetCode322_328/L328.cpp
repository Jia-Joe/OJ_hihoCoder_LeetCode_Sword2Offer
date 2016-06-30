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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *p0=head, *p1, *pt;
        if(p0==NULL||p0->next==NULL)//||p0->next->next==NULL) 
            return head;
        p1=head->next,pt=p1;
        while(p1->next){
            p0->next=p1->next;
            p1->next=p1->next->next;
            p0->next->next=pt;
            p0=p0->next;
            if(p1->next==NULL) break;
            p1=p1->next;
        }
        return head;
    }
};