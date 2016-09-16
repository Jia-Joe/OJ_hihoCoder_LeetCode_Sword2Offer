int lengthOfLIS(vector<int>& nums) {
	int sz = nums.size();
	if (!sz) return 0;
	vector<int> v(sz, 0);
	v[0] = nums[0];
	int mx=0,p,q,mid;
	for (int i = 1; i < sz; i++){
		p = 0; q = mx;
		while (p <= q){
			mid = p + (q - p) / 2;
			if (nums[i] < v[mid]) 
				q = mid - 1;
			else if(nums[i] > v[mid])
				p = mid + 1;
			else break;
		}
		if (v[mid]>=nums[i])
			v[mid] = nums[i];
		else
			v[mid + 1] = nums[i];
		if (p>mx) mx = p;
	}
	
	return mx+1;
}
vector<int> v = { 10, 9, 2, 5, 5, 8,8,8,8, 6, 4,1,7,7,7,7,7,7,7, 6, 18 }, v2 = { 10, 9, 2, 5, 3, 7, 101, 18 };
//int lengthOfLIS(vector<int>& nums) {
//	int sz = nums.size(),re=0;
//	if (!sz) return 0;
//	vector<int> v(sz, 1);
//	for (int i = 1; i < sz; i++){
//		for (int j = 0; j < i; j++){
//			if (nums[i]>nums[j] && v[i] < v[j] + 1)
//				v[i] = v[j] + 1;
//		}
//	}
//	for (int i = 0; i < sz; i++){
//		if (re < v[i]) re = v[i];
//	}
//	return re;
//}


int lengthOfLNDS(vector<int>& nums) {
	int sz = nums.size(),re=0;
	if (!sz) return 0;
	vector<int> v(sz, 1);
	for (int i = 1; i < sz; i++){
		for (int j = 0; j < i; j++){
			if (nums[i]>=nums[j] && v[i] < v[j] + 1)
				v[i] = v[j] + 1;
		}
	}
	for (int i = 0; i < sz; i++){
		if (re < v[i]) re = v[i];
	}
	return re;
}

int LNDS(vector<int>& nums) {
	int sz = nums.size();
	if (!sz) return 0;
	vector<int> v(sz, 0);
	v[0] = nums[0];
	int mx = 0, p, q, mid;
	bool f = 0;
	for (int i = 1; i < sz; i++){
		p = 0; q = mx;
		while (p <= q){
			mid = p + (q - p) / 2;
			if (nums[i] < v[mid])
				q = mid - 1;
			else if (nums[i] > v[mid])
				p = mid + 1;
			else {
				while (mid <= mx&&v[mid] == nums[i])
					mid++;
				f = 1; break;
			}
		}
		if (f&&mid > mx) {
			mx = mid;
			v[mx] = nums[i];
		}
		else{
			if (v[mid] > nums[i])
				v[mid] = nums[i];
			else
				v[mid + 1] = nums[i];
			if (p>mx) mx = p;
		}		
	}

	return mx + 1;
}