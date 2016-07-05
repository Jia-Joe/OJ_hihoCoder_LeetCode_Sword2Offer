/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
	vector<int> printListFromTailToHead(struct ListNode* head) {
		vector<int> ans;
		stack<int> st;
		ListNode *p = head;
		while (p){
			st.push(p->val);
			p = p->next;
		}
		while (!st.empty()){
			ans.push_back(st.top());
			st.pop();
		}
		return ans;
	}
};