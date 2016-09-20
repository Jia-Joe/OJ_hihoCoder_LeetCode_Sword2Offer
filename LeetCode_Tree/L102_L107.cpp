class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
    	vector<vector<int>> r;
    	if (!root) return r;
    	queue<pair<TreeNode*,int>> q; q.push(make_pair(root,0));	
    	while (!q.empty()){
    		TreeNode* t = q.front().first;
    		int c = q.front().second;
    		if (c >= r.size()) r.push_back(vector<int>(1, t->val));
    		else r[c].push_back(t->val);
    		q.pop();
    		if (t->left){
    			q.push(make_pair(t->left, c + 1));
    		}
    		if (t->right){
    			q.push(make_pair(t->right, c + 1));
    		}
    	}
    	return r;
    }
};

class Solution {
public:
    int getdp(TreeNode* root){
    	if (!root) return 0;
    	return max(getdp(root->left), getdp(root->right))+1;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
    	vector<vector<int>> r;
    	if (!root) return r;
    	int d = getdp(root),k=1;
    	for (int i = 0; i < d; i++) r.push_back(vector<int>{});
    	queue<TreeNode*> q; q.push(root);
    	while (!q.empty()){
    		int sz = q.size();		
    		for (int i = 0; i < sz; i++){
    			TreeNode* t = q.front();
    			r[d - k].push_back(t->val);
    			if (t->left) q.push(t->left);
    			if (t->right) q.push(t->right);
    			q.pop();
    		}
    		k++;
    	}
    	return r;
    }
};