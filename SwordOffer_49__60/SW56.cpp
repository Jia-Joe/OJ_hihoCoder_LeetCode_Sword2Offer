class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if (pHead == NULL || pHead->next == NULL) return pHead;
        bool fi = 1;
        ListNode* p1 = pHead, *p2 = pHead->next, *pf = p1,  *pr = NULL,*pt=p1;
        if (p1->val != p2->val){ pr = p1; fi = 0; }
        else{
            for (pt = p1; pt->next->next != NULL; pt = pt->next){
                if (pt->val != pt->next->val&&pt->next->val != pt->next->next->val){
                    pr = pt->next; fi = 0; break;
                }
            }
        }
        if (fi){
            if (pt->val == pt->next->val) return pr;
            else return pt->next;
        }
        pf = pr;
        ListNode* prf = pr;
        for (pt = pr; pt->next->next != NULL; pt = pt->next){
            if (pt->val != pt->next->val&&pt->next->val != pt->next->next->val){
                pf->next = pt->next;
                pf = pt->next;
            }
        }
        if (pt->val != pt->next->val){
            pf->next = pt->next;
        }
        else pf->next = NULL;
        return pr;
    }
};