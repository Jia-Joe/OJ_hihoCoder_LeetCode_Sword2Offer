/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        else
            return ok(root->left,root->right);
    }
    bool ok(TreeNode* r1,TreeNode* r2){
        if(r1==NULL&&r2==NULL) return true;
        if(r1&&r2&&r1->val==r2->val)
            return ok(r1->right,r2->left)&&ok(r1->left,r2->right);
        else
            return false;
    }
};