class Solution {
public:
	stack<int> st;
	stack<int> sm;
	void push(int value) {
		if (sm.empty()||value <= sm.top())
			sm.push(value);
		st.push(value);
	}
	void pop() {
		if (st.top() == sm.top())
			sm.pop();
		st.pop();
	}
	int top() {
		return st.top();
	}
	int min() {
		return sm.top();
	}
};