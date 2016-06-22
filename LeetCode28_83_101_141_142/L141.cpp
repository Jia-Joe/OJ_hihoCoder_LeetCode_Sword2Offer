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
        ListNode *p1=head,*p2=head;
        if(p2==NULL) return false;
        bool ret=false;
        while(p2->next!=NULL){
            p2=p2->next;
            if(p2->next==NULL) break;
            else p2=p2->next;
            p1=p1->next;
            if(p2==p1){
                return true;
            }
        }
        return ret;
    }
};