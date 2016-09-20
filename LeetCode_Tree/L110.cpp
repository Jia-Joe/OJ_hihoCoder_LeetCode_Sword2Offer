class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p&&!q) return 1;
        if(!p||!q||p->val!=q->val) return 0;
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
};