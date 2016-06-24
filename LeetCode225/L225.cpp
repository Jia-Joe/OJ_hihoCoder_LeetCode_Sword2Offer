class Stack {
public:
	queue<int> q1;
	queue<int> q2;
	queue<int> *pt, *pb;
	void decide(){
		if (q1.size()){
			pt = &q1; pb = &q2;
		}
		else{
			pt = &q2; pb = &q1;
		}
	}
	// Push element x onto stack.
	void push(int x) {
		decide();
		pt->push(x);
	}

	// Removes the element on top of the stack.
	void pop() {
		decide();
		int n = pt->size();
		while (--n){
			pb->push(pt->front());
			pt->pop();
		}
		pt->pop();
	}

	// Get the top element.
	int top() {
		decide();
		int n = pt->size(), ret;
		while (n--){
			if (n == 0)
				ret = pt->front();
			pb->push(pt->front());
			pt->pop();
		}
		return ret;
	}

	// Return whether the stack is empty.
	bool empty() {
		return !q1.size() && !q2.size();
	}
};