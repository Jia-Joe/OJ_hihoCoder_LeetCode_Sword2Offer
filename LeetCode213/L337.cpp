struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int rob(TreeNode* root) {
    	unordered_map<TreeNode*, int> mp;
    	return getrob(root, mp);
    }
    int getrob(TreeNode* root, unordered_map<TreeNode*, int> &mp){
    	if (!root) return 0;
    	auto it = mp.find(root);
    	if (it != mp.end()) return it->second;
    	int val = 0;
    	if (root->right)
    		val += getrob(root->right->left, mp) + getrob(root->right->right, mp);
    	if (root->left)
    		val += getrob(root->left->left, mp) + getrob(root->left->right, mp);
    	val = max(val + root->val, getrob(root->left, mp) + getrob(root->right, mp));
    	mp.insert(make_pair(root, val));
    	return val;
    }
};

class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> res = robSub(root);
        return max(res[0], res[1]);
    }
      
    vector<int> robSub(TreeNode* root) {
        if (root == NULL) {
            return vector<int>(2,0);
        }
    
        vector<int> left = robSub(root->left);
        vector<int> right = robSub(root->right);
    
        vector<int> res(2,0);
        res[0] = max(left[0], left[1]) + max(right[0], right[1]);
        res[1] = root->val + left[0] + right[0];
    
        return res;
    }
};
