void BTPdfs(vector<int> &v, vector<string> &vs, TreeNode* r){
	if (!r) return;
	v.push_back(r->val);
	if (!r->left&&!r->right){
		string re;
		for (int i = 0; i < v.size(); i++){
			stringstream ss;
			ss << v[i];
			string st = ss.str();
			re.append(st);
			if (i != v.size() - 1)
				re.append("->");
		}
		vs.push_back(re);
	}
	if (r->left){		
		BTPdfs(v,vs,r->left);
	}
	if (r->right){
		BTPdfs(v, vs, r->right);
	}
	v.pop_back();
	return;
}

vector<string> binaryTreePaths(TreeNode* root) {
	vector<string> vs;
	vector<int> v;
	BTPdfs(v, vs, root);
	return vs;
}