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

//P(n,k)
class Solution {
public:
    void dfsp(vector<int> &v, vector<bool> &mk, int cnt, int k, vector<vector<int>> &ans){
    	int sz = v.size();
    	if (k > sz){ printf("Error!\n"); return; }
    	if (cnt == k){
    		vector<int> vr(k);
    		for (int i = 0; i < k; i++){
    			vr[i] = v[i];
    		}
    		ans.push_back(vr);
    	}
    	for (int i = 1; i <= sz; i++){
    		if (!mk[i]){
    			mk[i] = 1;
    			v[cnt] = i;
    			dfsp(v, mk, cnt + 1, k, ans);
    			mk[i] = 0;
    		}
    	}
    }
    vector<vector<int>> permute(vector<int>& nums, int k) {
    	int sz = nums.size();//,k=sz;
    	sort(nums.begin(), nums.end());
    	vector<int> vt(sz);
    	vector<bool> mk(sz+1, 0);
    	vector<vector<int>> ans;
    	dfsp(vt, mk, 0, k, ans);
    
    	int rsz = ans.size();
    	vector<vector<int>> ret=ans;
    	for (int i = 0; i < rsz; i++){
    		for (int j = 0; j < k; j++){
    			ret[i][j] = nums[ans[i][j]-1];
    		}
    	}
    	return ret;
    }
};
