class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        if(!root) return v;
        rec(root,v);
        return v;
    }
    void rec(TreeNode* root,vector<int> &v){
        if(root->left)rec(root->left,v);
        if(root->right)rec(root->right,v);
        if(root) v.push_back(root->val);
    }
};

vector<int> postorderTraversal(TreeNode* root) {
	vector<int> v;
	unordered_map<TreeNode*,int> mp;
	if (!root) return v;
	stack<TreeNode* > st;
	st.push(root);
	while (!st.empty()){
		TreeNode* t = st.top();
		if (!t->left&&!t->right){
			v.push_back(t->val);
			st.pop();
			continue;
		}
		auto it = mp.find(t);
		if (it == mp.end()){
			mp[t] = 0;
			st.push(t);
			if (t->right)st.push(t->right);			
			if (t->left)st.push(t->left);
		}
		else{
			if (mp[t] == 0){
				v.push_back(t->val);
				mp[t]++;
			}
			st.pop();
		}
	}
	return v;
}