class Solution {
public:
    void mids(TreeNode* r, vector<pair<int, TreeNode*>> &v){
        if (!r) return;
        mids(r->left, v);
        v.push_back(make_pair(r->val, r));
        mids(r->right, v);
    }

    TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
    {
        if (pRoot == NULL||k<=0) return NULL;
        vector<pair<int, TreeNode*>> v;
        mids(pRoot, v);
        if (k > v.size()) return NULL;
        return v[k-1].second;
    }
 
     
};