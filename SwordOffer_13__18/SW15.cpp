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
    ListNode* ReverseList(ListNode* pHead) {
        if(!pHead||!pHead->next) return pHead;
        ListNode *p1=pHead->next, *p2, *temp;
        pHead->next=NULL;
        while(p1){
            p2=p1;
            p1=p1->next;
            temp=pHead;
            pHead=p2;
            p2->next=temp;
            
        }
        return pHead;
    }
};