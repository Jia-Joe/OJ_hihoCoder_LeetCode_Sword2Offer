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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		////////////SIGNIFICANT!///////////////
        if (pListHead == NULL || k <= 0) return NULL;
		///////////////////////////////
        ListNode *p1 = pListHead, *p2 = pListHead;
        for(int i=1;i<k;++i){
            if (p2->next == NULL)
                return NULL;
            else
                p2 = p2->next;                		
        }

        while (p2->next){
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};