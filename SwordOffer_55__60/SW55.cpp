/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if (!pHead) return NULL;
        ListNode* slow = pHead, *fast = pHead;
        while (fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) break;
        }
        if (!fast->next || !fast->next->next) return NULL;
        fast = pHead;
        while (fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};