class Solution {
public:
    int find(TreeNode* root,bool f){
        if(!root) return 0;
        if(!root->left&&!root->right&&f) return root->val;
        int sum=find(root->left,1)+find(root->right,0);
        return sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return find(root,0);
    }
};