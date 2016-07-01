class Solution {
public:
    void swap(vector<int>& v,int i,int j){
        int t=v[i];
        v[i]=v[j]; v[j]=t;
    }
    void perm(vector<vector<int>> &ans,vector<int>& v,int begin,int end){
        if(begin==end){
            ans.push_back(v);
            return;
        }
        else{
            for(int i=begin;i<=end;++i){
                swap(v,begin,i);
                perm(ans,v,begin+1,end);
                swap(v,begin,i);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        perm(ans,nums,0,nums.size()-1);
        return ans;
    }
};