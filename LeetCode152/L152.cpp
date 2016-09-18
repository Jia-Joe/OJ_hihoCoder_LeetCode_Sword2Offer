class Solution {
public:
    int maxProduct(vector<int>& nums) {
    	int n = nums.size(), si = 0, sa = 0;
    	if(n==0) return 0;
    	vector<int> va(n), vi(n);
    	va[0] = nums[0], vi[0] = nums[0];
    	int re = nums[0];
    	for (int i = 1; i<n; i++){
    		vi[i] = min(nums[i], min(nums[i] * vi[i - 1], nums[i] * va[i - 1]));
    		va[i] = max(nums[i], max(nums[i] * vi[i - 1], nums[i] * va[i - 1]));
    		if (re < va[i]) re = va[i];
    	}
    	return re;
    }
};