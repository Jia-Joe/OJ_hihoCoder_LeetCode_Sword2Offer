class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if (pRoot == NULL) return 0;
        return 1 + max(TreeDepth(pRoot->left), TreeDepth(pRoot->right));
    }
};

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
    int TreeDepth(TreeNode* pRoot)
    {
        int ret = 0, su=0 ;
        if (pRoot == NULL) return 0;
        stack<TreeNode*> st;
        unordered_map<TreeNode*,int> mp;
        st.push(pRoot); 
        mp[pRoot] = 1;
        while (!st.empty()) {
            TreeNode* tp = st.top();
            st.pop();
            if (!tp->left&&!tp->right&&ret < mp[tp])
                ret = mp[tp];
            if (ret < su) ret = su;
            if (tp->left){
                st.push(tp->left);
                mp[tp->left] = mp[tp] + 1;
            }
            if (tp->right){
                st.push(tp->right);
                mp[tp->right] = mp[tp] + 1;
            }
        }
        return ret;
    }
};