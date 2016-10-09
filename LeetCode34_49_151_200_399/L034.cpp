class Solution {
public:
    bool bis(vector<int>&v, int wp, int wq, float x, int &m){
    	int p = wp, q = wq;
    	while (p <= q){
    		m = p + (q - p) / 2;
    		if (x<v[m]) q = m - 1;
    		else if (x>v[m]) p = m + 1;
    		else return 1;
    	}
    	return 0;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
    	vector<int> res = { -1, -1 };
    	int sz = nums.size(), t=0, m1=0, m2=0;
    	bool fm = bis(nums, 0, sz - 1, target, t);
    	if (!fm) return res;
    	bis(nums, 0, sz - 1, target - 0.5, m1);
    	bis(nums, 0, sz - 1, target + 0.5, m2);
    	int lt = 0, rt = sz - 1;
    	if (m1 >= 0){
    		if (nums[m1] != target) m1++;
    		lt = m1;
    	}
    	if (m2<sz){
    		if (nums[m2] != target) m2--;
    		rt = m2;
    	}
    	res[0] = lt, res[1] = rt;
    	return res;
    }
};

vector<int> searchRange(vector<int>& nums, int target) {
	vector<int> res = { -1, -1 };
	int lo = 0, hi = nums.size()- 1;
	while (nums[lo] < nums[hi]) {
		int mid = lo + (hi - lo) / 2;
		if (nums[mid] > target) {
			hi = mid - 1;
		}
		else if (nums[mid] < target) {
			lo = mid + 1;
		}
		else {
			if (nums[lo] == nums[mid]) {
				hi--;
			}
			else {
				lo++;
			}
		}
	}
	if (nums[lo] == nums[hi] && nums[lo] == target) {
		res[0] = lo;
		res[1] = hi;
	}
	return res;
}