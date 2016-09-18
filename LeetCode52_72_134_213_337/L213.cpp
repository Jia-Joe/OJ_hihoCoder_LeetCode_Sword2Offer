class Solution {
public:
    int rob(vector<int>& nums) {
        int sz = nums.size();
        if(!sz) return 0;
        if(sz==1) return nums[0];
        vector<int> v1(nums.begin(), nums.begin() + sz - 1);
	    vector<int> v2(nums.begin() + 1, nums.begin() + sz);
        int re1=rob1(v1),re2=rob1(v2);
        return re1>re2?re1:re2;        
    }
    int rob1(vector<int>& nums) {
    	int sz = nums.size();
    	if (sz == 0) return 0;
    	vector<int> v(sz + 1, 0);
    	v[1] = nums[0];
    	for (int i = 2; i <= sz; i++){
    		v[i] = v[i - 1]>v[i - 2] + nums[i - 1] ? v[i - 1] : v[i - 2] + nums[i - 1];
    		
        	for(int w=0;w<=i;w++){
                 cout<<v[w]<<" ";
            }
            cout<<endl;	
    	}
    	
    	return v[sz];
    }    
};