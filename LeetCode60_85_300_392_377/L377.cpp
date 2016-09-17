class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
    	int sz = nums.size();
    	vector<int> dp(target + 1, 0);
    	dp[0] = 1;
    	for (int i = 1; i <= target; i++){
    		for (int j = 0; j < sz; j++){
    			if (i >= nums[j])
    				dp[i] += dp[i - nums[j]];
    		}
    		//for (int k = 0; k < target + 1; k++) cout << dp[k];
    		//cout << endl;
    	}
    	
    	return dp[target];
    }
};