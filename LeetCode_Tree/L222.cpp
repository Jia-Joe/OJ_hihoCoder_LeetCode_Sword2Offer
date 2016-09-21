class Solution {
public:
    int findx(TreeNode* root,int x,int d) {
        TreeNode* p=root;
    	while(d){
    	    if((x&d)==0)p=p->left;
    	    else p=p->right;
    	    d>>=1;
    	}
    	if(p->left&&p->right) return 1;
    	if(!p->left&&!p->right) return -1;
    	return 0;
    }
    int countNodes(TreeNode* root) {
    	if (!root) return 0;
    	int dp=0,d=1;
    	TreeNode* p=root;
    	while(p->right){
    	    p=p->right; dp++;
    	}
    	if(dp==0) return root->left?2:1;
    	d=d<<(dp-1);
    	int x1=0,x2=d*2-1,m,w;
    	while(x1<=x2){
    	    m=x1+(x2-x1)/2;
    	    w=findx(root,m,d);
    	    if(w==-1) x2=m-1;
    	    else if(w==1) x1=m+1;
    	    else{
    	        cout<<m<<endl;
    	        return (d*2+m)*2;
    	    }
    	}
    	if(w==1) return (d*2+m)*2+1;
    	if(m==0) return d*4-1;
    	else return (d*2+m-1)*2+1;
    }
};