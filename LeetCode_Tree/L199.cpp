class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if(!root) return v;
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            int sz=qu.size();
            for(int i=0;i<sz;i++){
                TreeNode* t=qu.front();
                if(t->left) qu.push(t->left);
                if(t->right) qu.push(t->right);
                if(i==sz-1) v.push_back(t->val);
                qu.pop();
            }
        }
        return v;
    }
};