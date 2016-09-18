/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool oksym(TreeNode *tr1, TreeNode *tr2){
        if (!tr1&&!tr2) return true;
        if (!tr1 || !tr2) return false;
        return tr1->val == tr2->val&&oksym(tr1->left, tr2->right) && oksym(tr1->right, tr2->left);
    }
    bool isSymmetrical(TreeNode* pRoot)
    {
        if (!pRoot) return true;
        return oksym(pRoot->left, pRoot->right);
    }

};