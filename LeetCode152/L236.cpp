    void getbk(unordered_map<TreeNode*, TreeNode*> &mp, TreeNode* r){
    	if (r->left){
    		mp[r->left] = r;
    		getbk(mp, r->left);
    	}	
    	if (r->right){
    		mp[r->right] = r;
    		getbk(mp, r->right);
    	}
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	if (!root) return 0;
    	unordered_map<TreeNode*, TreeNode*> mp;
    	mp[root] = 0;
    	vector<TreeNode*> vp, vq;
    	vp.push_back(p); vq.push_back(q);
    	TreeNode* t = p;
    	getbk(mp, root);
    	while (mp[t]){
    		t = mp[t];
    		vp.push_back(t); cout << t->val<<" ";
    	}
    	t = q;
    	while (mp[t]){
    		t = mp[t];
    		vq.push_back(t); cout << t->val<<"-";
    	}
    	int i = vp.size() - 1, j = vq.size() - 1;
    	for (; vp[i] == vq[j]; i--, j--){
    		if (i == 0) return vp[0];
    		if (j == 0) return vq[0];
    	}cout << vp[i+1]->val;
    	return vp[i+1];
    }