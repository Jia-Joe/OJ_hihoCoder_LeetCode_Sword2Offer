class Solution {
public:
    int maxDepth(TreeNode* root) {
    	if(!root) return 0;
    	return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return 1;
        return abs(maxDepth(root->left)-maxDepth(root->right))<2&&isBalanced(root->left)&&isBalanced(root->right);
    }
};