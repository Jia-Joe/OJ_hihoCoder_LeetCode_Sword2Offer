/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        if(n==0) return ans;
        ans=shape(n);

        for(int i=0;i<ans.size();++i){
            int cnt=1;
            fill(ans[i],cnt);
        }
            
        return ans;
    }
    vector<TreeNode*> shape(int n){
        vector<TreeNode*> ans;
        if(n==0) ans.push_back(NULL);
        if(n==1) ans.push_back(new TreeNode(1));
        else{
            for(int i=0;i<n;++i){
                for(TreeNode* lt:shape(i)){
                    for(TreeNode* rt:shape(n-1-i)){
                        TreeNode* sht=new TreeNode(0);
                        sht->left=lt;
                        sht->right=rt;
                        ans.push_back(sht);
                    }
                }
            }
        }
        return ans;
    }
    void fill(TreeNode* tr,int& cnt){
        if(tr){
            if(tr->left) fill(tr->left,cnt);
            tr->val=cnt++;
            if(tr->right) fill(tr->right,cnt);    
        }
    }
    
};