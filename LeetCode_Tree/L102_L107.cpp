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