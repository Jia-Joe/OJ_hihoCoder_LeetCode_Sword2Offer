class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while((p->val - root->val)*(q->val - root->val)>0)
    	if (p->val < root->val)
    		root=root->left;
    	else
    		root=root->right;
    	return root;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	if (!root) return 0;
    	if (root == p || root == q) return root;
    	if (!root->left) return lowestCommonAncestor(root->right, p, q);
    	if (!root->right) return lowestCommonAncestor(root->left, p, q);
    	if (p->val <= root->val&&q->val <= root->val)
    		return lowestCommonAncestor(root->left, p, q);
    	if (p->val >= root->val&&q->val >= root->val)
    		return lowestCommonAncestor(root->right, p, q);
    	return root;
    }
};