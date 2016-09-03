class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (!next_permutation(nums.begin(), nums.end())){
			sort(nums.begin(), nums.end());
		}
		for (int i = 0; i<nums.size(); i++){
			cout << nums[i];
		}
		return;
	}
};

class Solution {
public:
    void swap(vector<int>& v, int i, int j){
    	int t = v[i]; v[i] = v[j]; v[j] = t;
    }
    void reverse(vector<int>& v, int i, int j){
    	int p = i, q = j;
    	while (p<q){
    		swap(v, p, q);
    		p++; q--;
    	}
    }
    void nextPermutation(vector<int>& nums) {
    	int n = nums.size(), i = n - 1;
    	for (; i >= 1; i--){
    		if (nums[i - 1]<nums[i]){
    			for (int j = i; j<n; j++){
    				if (nums[j] <= nums[i - 1]){
    					swap(nums, j - 1, i - 1);
    					break;
    				}
    				if (j == n - 1)
					    swap(nums, j, i - 1);
    			}
    			reverse(nums, i, n - 1);
    			break;
    		}
    	}
    	if(i==0) reverse(nums,0,n-1);
    	return;
    }
};