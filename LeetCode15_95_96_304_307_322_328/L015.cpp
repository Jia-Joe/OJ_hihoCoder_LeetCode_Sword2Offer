class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	vector<vector<int>> ret;
    	if (count(nums.begin(), nums.end(), 0) >= 3)
    		ret.push_back({ 0, 0, 0 });
    	unordered_map<int, int> mp;
    	for (int i = 0; i < nums.size(); i++){
    		if (mp.find(nums[i]) == mp.end())
    			mp[nums[i]] = 1;
    		else
    			mp[nums[i]]++;
    	}
    	sort(nums.begin(), nums.end());
    	auto vend = unique(nums.begin(), nums.end());
    	nums.erase(vend, nums.end());
    	int sz = nums.size();
    	for (int i = 0; i < sz; i++){
    		for (int k = i + 1; k < sz; k++){
    			if (nums[k] == -2 * nums[i] || nums[i] == -2 * nums[k]){
    				int res = -nums[i] - nums[k];
    				auto it = mp.find(res);
    				if (it != mp.end()){
    					if (it->second == 1)
    						continue;
    					ret.push_back({ nums[i], nums[k], res });
    				}
    			}			
    		}
    	}
    	for (int i = 0; i < sz; i++){
    		mp.erase(mp.find(nums[i]));
    		for (int k = i + 1; k < sz; k++){
    			mp.erase(mp.find(nums[k]));
    			int res = -nums[i] - nums[k];
    			if (mp.find(res)!= mp.end()){
    				ret.push_back({ nums[i], nums[k], res });
    			}
    		}
    		for (int k = i + 1; k < sz; k++){
    			mp[nums[k]] = 1;
    		}
    	}
    	return ret;
    }
};

//Two Pointer
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() && nums[i] <= 0; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int sum = -nums[i];
            for (int j = i + 1, k = nums.size() - 1; j < k;) {
                int tmp = nums[j] + nums[k];
                if (sum == tmp) {
                    ret.push_back({nums[i], nums[j], nums[k]});
                    while (j < nums.size() - 1 && nums[j] == nums[j + 1]) 
                        ++j;
                    while (k > j && nums[k] == nums[k - 1]) 
                        --k;
                    ++j;
                    --k;
                }
                else if (tmp < sum) ++j;
                else --k;
            }
        }
        return ret;
    }
};