class BSTIterator {
private:
    TreeNode *root, *p;
    void findnext(TreeNode *root, TreeNode* &pn, TreeNode* &gt){
    	if (!root) return;
    	if(!gt||root->val>gt->val)findnext(root->left, pn, gt);
    	if (pn == gt){
    		gt = root;
    		return;
    	}
    	pn = root;
    	if (root->val<=gt->val)findnext(root->right, pn, gt);
    }
public:
    BSTIterator(TreeNode *root) {
        this->root=root;
        p=0;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(!root) return 0;
        TreeNode *pn=0,*t=p;
        findnext(root,pn,t);
        return t!=p;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *pn=0;
        findnext(root,pn,p);
        return p->val;
    }
};

class TreeIterator {
private:
    TreeNode *root, *p;
    void findnext(TreeNode *root, TreeNode* &pn, TreeNode* &gt){
    	if (!root) return;
    	findnext(root->left, pn,gt);
    	if (pn == gt){
    		gt = root;
    		return;
    	}
    	if (root&&pn) cout << "root:" << root->val << "   pn:" << pn->val << endl;
    	else{
    		if (root)cout << "root:" << root->val << endl;
    		if (pn)cout << "pn:" << pn->val << endl;
    	}
    	pn = root;
    	findnext(root->right, pn,gt);
    }
public:
    BSTIterator(TreeNode *root) {
        this->root=root;
        p=0;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(!root) return 0;
        TreeNode *pn=0,*t=p;
        findnext(root,pn,t);
        return t!=p;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *pn=0;
        findnext(root,pn,p);
        return p->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */