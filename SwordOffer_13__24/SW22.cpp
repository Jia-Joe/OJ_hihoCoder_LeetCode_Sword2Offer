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
    vector<int> PrintFromTopToBottom(TreeNode *root) {
        vector<int> v;
        if (root == NULL) return v;
        queue<TreeNode*> qu;
        qu.push(root);
        v.push_back(root->val);
        while (!qu.empty()){
            TreeNode* t = qu.front();
            qu.pop();
            if (t->left) { 
                qu.push(t->left); 
                v.push_back(t->left->val);
            }
            if (t->right) { 
                qu.push(t->right);
                v.push_back(t->right->val);

            }
        }
        return v;
    }
};