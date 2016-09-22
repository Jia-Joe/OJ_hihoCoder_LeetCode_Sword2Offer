void findprev(TreeNode *root, TreeNode* &prev){
	if (!root) return ;	
	findprev(root->left, prev);
	if (root&&prev) cout << "root:" << root->val << "   prev:" << prev->val << endl;
	else{
		if (root)cout << "root:" << root->val << endl;
		if (prev)cout << "prev:" << prev->val << endl;
	}
	prev = root;
	findprev(root->right, prev);
}

void findpn(TreeNode *root, TreeNode* &pn){
	if (!root) return ;	
	findpn(root->left, pn);
	if (root&&pn) cout << "root:" << root->val << "   pn:" << pn->val << endl;
	else{
		if (root)cout << "root:" << root->val << endl;
		if (pn)cout << "pn:" << pn->val << endl;
	}
	pn = root;
	findpn(root->right, pn);
}