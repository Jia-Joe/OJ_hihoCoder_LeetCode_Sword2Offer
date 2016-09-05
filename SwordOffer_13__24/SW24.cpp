/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void dfs(TreeNode* r, vector<vector<int> > &v, stack<int> &st,int &s, int exp){
        st.push(r->val);
        s += r->val;
        if (r->left == NULL&&r->right == NULL&&s==exp){
            stack<int> sb; vector<int> vb;
            while (!st.empty()){
                sb.push(st.top());
                st.pop();
            }
            while (!sb.empty()){
                vb.push_back(sb.top());
                st.push(sb.top());
                sb.pop();
            }
            v.push_back(vb);
        }
        if (r->left){
            dfs(r->left, v, st, s, exp);
            st.pop();
            s -= r->left->val;
        }
        if (r->right){
            dfs(r->right, v, st, s, exp);
            st.pop();
            s -= r->right->val;
        }
        return;
    }

    vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
        vector<vector<int> > ret;
        if (root == NULL) return ret;
        stack<int> st;
        int s = 0;
        dfs(root, ret, st, s, expectNumber);
        //for (vector<int> v : ret){
        //	for (int x : v)
        //		cout << x << "  ";
        //	cout << endl;
        //}
        return ret;
    }
};