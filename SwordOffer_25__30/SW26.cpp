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
    TreeNode* convert(TreeNode* r)
    {
        if (r == NULL) return NULL;
        if (r->left == NULL&&r->right == NULL){
            r->left = r; r->right = r;
            return r;
        }
        TreeNode *lt = convert(r->left), *rt = convert(r->right);
        if (lt == NULL)
            lt = r;
        else{
            lt->left->right = r;
            r->left = lt->left;
            r->right = rt ? rt : lt;
        }
        if (rt == NULL)
            lt->left = r;
        else{
            lt->left = rt->left;
            rt->left->right = lt;
            rt->left = r;
        }

        return lt;
    }
    TreeNode* Convert(TreeNode* pRootOfTree){
        TreeNode* ans = convert(pRootOfTree);
        //No cycle
        if (ans){
            ans->left->right = NULL;
            ans->left = NULL;
        }
        return ans;
    }
};