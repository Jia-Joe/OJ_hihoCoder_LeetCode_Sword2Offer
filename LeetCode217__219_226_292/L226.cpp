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
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
    void invert(TreeNode* root){
        if(root==NULL) return;
        TreeNode* tp=root->left;
        root->left=root->right;
        root->right=tp;
        invert(root->left);
        invert(root->right);
    }
};