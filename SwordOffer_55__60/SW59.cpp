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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > ans;
        vector<int> v;
        if (pRoot == NULL) return ans;
        queue<pair<TreeNode*, int> > qu;
        qu.push(make_pair(pRoot, 0));
        v.push_back(pRoot->val);
        int x = -1;
        while (!qu.empty()){
            TreeNode* t = qu.front().first;
            int c = qu.front().second;
            qu.pop();
            if (c > x){
                ans.push_back(v);
                v.clear();
                ++x;
            }
            if (t->left) {
                qu.push(make_pair(t->left, c + 1));
                v.push_back(t->left->val);
            }
            if (t->right) {
                qu.push(make_pair(t->right, c + 1));
                v.push_back(t->right->val);

            }
        }
        int sz = ans.size();
        for (int i = 1; i < sz; i += 2){
            int sv = ans[i].size();
            for (int j = 0, k = sv - 1; j < k; ++j, --k){
                swap(ans[i][j], ans[i][k]);
            }
        }
        return ans;
    }
    
};