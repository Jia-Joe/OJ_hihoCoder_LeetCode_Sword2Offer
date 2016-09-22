class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
    	if (!root) return v;
    	stack<TreeNode*> st;
    	TreeNode* prev = 0;
    	st.push(root);
    	while (!st.empty()){
    		TreeNode *t = st.top();
    		v.push_back(t->val);
    		st.pop();
    		if (t->right){
    			st.push(t->right);
    		}
    		if (t->left){
    			st.push(t->left);
    		}
    	}
        return v;    
    }
};