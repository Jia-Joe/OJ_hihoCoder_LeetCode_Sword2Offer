/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    struct TreeNode* rebud(vector<int> pre, vector<int> in, int p, int q, int v, int r) {
        if (p > q)
            return NULL;
        TreeNode *tr = new TreeNode(pre[v]);
        if (p >= q)
            return tr;
        int i = -1;
        for (int k = p; k <= q; k++)
        {
            i++;
            if (in[k] == pre[v])
                break;
        }

        tr->left = rebud(pre, in, p, p + i - 1, v + 1, v + i);
        tr->right = rebud(pre, in, p + i + 1, q, v + i + 1, r);
        return tr;
    }
    struct TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in) {
        int n = pre.size();
        return rebud(pre, in, 0, n - 1,0,n-1);
    }

};