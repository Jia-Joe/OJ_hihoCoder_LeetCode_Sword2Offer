class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot1 == NULL || pRoot2 == NULL) return false;
		if (HasTree(pRoot1, pRoot2)) return true;
		return HasTree(pRoot1->left, pRoot2) || HasTree(pRoot1->right, pRoot2);
	}
	bool HasTree(TreeNode* pRoot1, TreeNode* pRoot2){
		if (pRoot2 == NULL) return true;
		if (pRoot1 == NULL) return false;
		return pRoot1->val == pRoot2->val && HasTree(pRoot1->left, pRoot2->left) && HasTree(pRoot1->right, pRoot2->right);
	}
};