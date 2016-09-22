class Solution {
public:
    TreeNode* mybd(vector<int>& preorder, vector<int>& inorder, int p1, int p2, int i1, int i2){
    	//cout << p1 << " " << p2 << " " << i1 << " " << i2 << endl;
    	int sz = p2 - p1 + 1;
    	if (sz < 1) return 0;
    	TreeNode *root = new TreeNode(preorder[p1]);
    	if (sz == 1) return root;
    	int i;
    	for (i = i1; i <= i2; i++){
    		if (inorder[i] == preorder[p1]) break;
    	}
    	i -= i1;
    	root->left = mybd(preorder, inorder, p1 + 1, p1 + i, i1, i1 + i - 1);		
    	root->right = mybd(preorder, inorder, p1 + i + 1, p2, i1 + i + 1, i2);
    	return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    	int sz = preorder.size();
    	if (!sz) return 0;	
    	return mybd(preorder, inorder, 0, sz - 1, 0, sz - 1);
    }
};

class Solution {
public:
    TreeNode* mybd(vector<int>& inorder, vector<int>& postorder, int p1, int p2, int i1, int i2){
    	//cout << p1 << " " << p2 << " " << i1 << " " << i2 << endl;
    	int sz = p2 - p1 + 1;
    	if (sz < 1) return 0;
    	TreeNode *root = new TreeNode(postorder[p2]);
    	if (sz == 1) return root;
    	int i;
    	for (i = i1; i <= i2; i++){
    		if (inorder[i] == postorder[p2]) break;
    	}
    	i -= i1;
    	root->left = mybd(inorder, postorder, p1, p1 + i - 1, i1, i1 + i - 1);
    	root->right = mybd(inorder, postorder, p1 + i, p2 - 1, i1 + i + 1, i2);
    	return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    	int sz = postorder.size();
    	if (!sz) return 0;
    	return mybd(inorder, postorder, 0, sz - 1, 0, sz - 1);
    }
};