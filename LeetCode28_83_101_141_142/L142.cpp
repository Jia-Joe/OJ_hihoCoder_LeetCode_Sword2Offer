/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //use set
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> st;
        ListNode *p=head;
        while(p!=NULL){
            if(st.find(p)!=st.end())
                break;
            st.insert(p);
            p=p->next;
        }
        return p;
    }
};

//Without using extra space
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        ListNode* slow = head, * fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) break;
        }
        if(!fast->next || !fast->next->next) return NULL;
        fast = head;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};

//ck=The number of Node in cycle
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *p1=head,*p2=head;
        bool hasCycle=false;
        if(!p2||!p2->next) return NULL;
        while(p2->next){
            p2=p2->next;
            if(!p2->next)
                return NULL;
            else
                p2=p2->next;
            p1=p1->next;
            if(p1==p2){
                hasCycle=true;
                break;
            }
                
        }
        if(hasCycle){
            p2=p2->next->next;
            p1=p1->next;        
            int ck=1;
            while(p1!=p2){
                p2=p2->next->next;
                p1=p1->next;
                ck++;
            }
            p1=head,p2=head;
            while(ck--) p2=p2->next;
            while(p1!=p2){
                p1=p1->next;
                p2=p2->next;
            }
            return p1;    
        }
        else
            return NULL;
    }
};