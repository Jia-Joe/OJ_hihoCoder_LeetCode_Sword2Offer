void flatten(TreeNode* root) {
	if (!root) return;
	stack<TreeNode*> st;
	TreeNode* prev = 0;
	st.push(root);
	while (!st.empty()){
		TreeNode *t = st.top();
		st.pop();
		if (t->right){
			st.push(t->right);
		}
		if (t->left){
			st.push(t->left);
		}
		if (prev){
			prev->right = t;
			prev->left = 0;
		}
		prev = t;
	}
}

class Solution {
private: 
    TreeNode* prev = NULL;
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};