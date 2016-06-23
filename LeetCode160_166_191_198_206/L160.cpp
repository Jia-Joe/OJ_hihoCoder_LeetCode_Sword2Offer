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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1=headA, *p2=headB, *ps, *pl;
        if(!p1||!p2) return NULL;
        while(p1->next&&p2->next){
            p1=p1->next;
            p2=p2->next;
        }
        int dif=0;
        if(!p1->next){
            while(p2->next){
                p2=p2->next;
                dif++;
            }
            if(p1!=p2) return NULL;
            ps=headA; pl=headB;
        }
        else{
            while(p1->next){
                p1=p1->next;
                dif++;
            }
            if(p1!=p2) return NULL;
            ps=headB; pl=headA;
        }
        while(dif--) pl=pl->next;
        while(pl!=ps){
            pl=pl->next;
            ps=ps->next;
        }
        return pl;
    }
};