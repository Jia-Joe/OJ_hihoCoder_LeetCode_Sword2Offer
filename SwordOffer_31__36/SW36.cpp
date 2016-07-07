class Solution {
public:
    ListNode* FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) {
        ListNode *p1 = pHead1, *p2 = pHead2, *p3, *p4, *ps;
        if (!p1 || !p2) return NULL;
        while (p1&&p2){
            p1 = p1->next;
            p2 = p2->next;
        }
        if (p1) {
            p3 = p1; p4 = pHead1; ps = pHead2;
        }
        else {
            p3 = p2; p4 = pHead2; ps = pHead1;
        }
        while (p3) {
            p3 = p3->next; p4 = p4->next;
        }
        while (ps){
            if (ps == p4) return  ps;
            ps = ps->next; p4 = p4->next;
        }
        return NULL;
    }
};