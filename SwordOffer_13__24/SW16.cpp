/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1 == NULL) return pHead2;
        if (pHead2 == NULL) return pHead1;
        ListNode *tp, *ret = pHead1->val < pHead2->val ? pHead1 : pHead2, *p1 = ret, *p2 = ret == pHead1 ? pHead2 : pHead1, *pre = p1;
        p1 = p1->next;
        while (p1&&p2){
            while (p1&&p1->val < p2->val){
                p1 = p1->next;
                pre = pre->next;
            }
            if (p1 == NULL) break;

            tp = p2;
            p2 = p2->next;
            tp->next = p1;
            pre->next = tp;
            pre = p1;
            p1 = p1->next;

        }
        if (p2){
            pre->next = p2;
        }
        return ret;
    }
};