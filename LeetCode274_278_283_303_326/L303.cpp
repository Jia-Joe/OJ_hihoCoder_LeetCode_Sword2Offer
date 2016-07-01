class NumArray {
public:
	int* sum;
	NumArray(vector<int> &nums) {
		int sz = nums.size();
		sum = new int[sz + 1];
		sum[0] = 0;
		for (int i = 1; i<sz + 1; i++)
			sum[i] = nums[i-1] + sum[i - 1];
	}

	int sumRange(int i, int j) {
		return sum[j + 1] - sum[i];
	}
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
