class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return 1;
    	vector<int> v;
    	dfs98(root,v);
    	for (int i = 0; i < v.size() - 1; i++){
    		if (v[i] >= v[i + 1]) return 0;
    	}
    	return 1;
    }
    void dfs98(TreeNode* root,vector<int> &v){
    	if (!root) return;
    	if (root->left) dfs98(root->left, v);
    	v.push_back(root->val);
    	if (root->right) dfs98(root->right, v);
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev=NULL;
    	return ok(root,prev);
    }
    bool ok(TreeNode* root,TreeNode* &prev){
    	if(!root) return 1;
    	if(!ok(root->left,prev)) return 0;
    	if(prev!=NULL&&prev->val>=root->val) return 0;
    	if(root&&prev) cout<<"root:"<<root->val<<"   prev:"<<prev->val<<endl;
    	else{
    	    if(root)cout<<"root:"<<root->val<<endl;
    	    if(prev)cout<<"prev:"<<prev->val<<endl;
    	}
    	prev=root;
    	return ok(root->right,prev);
    }
};
