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
		if (mid+1>mx) mx = p;
	}
	
	return mx+1;
}
