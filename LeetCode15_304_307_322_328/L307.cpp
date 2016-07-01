class NumArray {
private:
	vector<int> v;
	vector<int> ix;
	//Segment Tree
	struct SegTree{
		int a, b, su, left = NULL, right = NULL;
		//SegTree(int x) :a(x), left(NULL), right(NULL){};
	} sgtree[35000];
	void build(int a, int b, int &tot){
		int now;
		tot++; now = tot;
		sgtree[now].a = a;
		sgtree[now].b = b;
		if (b > a){
			int mid = (a + b) >> 1;
			sgtree[now].left = tot + 1;
			build(a, mid, tot);
			sgtree[now].right = tot + 1;
			build(mid + 1, b, tot);
		}
		else
			ix.push_back(tot);
	}
	int getsum(int n){
		if (sgtree[n].a == sgtree[n].b){
			sgtree[n].su = v[sgtree[n].a];
			return v[sgtree[n].a];
		}
		sgtree[n].su = getsum(sgtree[n].left) + getsum(sgtree[n].right);
		return sgtree[n].su;
	}
	int sumhelper(int i, int j, int nx){
		if (i <= sgtree[nx].a&&j >= sgtree[nx].b) return sgtree[nx].su;
		int mid = (sgtree[nx].a + sgtree[nx].b) >> 1;
		if (i > mid) return sumhelper(i, j, sgtree[nx].right);
		if (j <= mid) return sumhelper(i, j, sgtree[nx].left);
		return sumhelper(i, j, sgtree[nx].left) + sumhelper(i, j, sgtree[nx].right);

	}
public:	
	NumArray(vector<int> &nums) {
		int sz = nums.size(), tot = 0;
		if (sz){
			for (int i = 0; i < sz; i++)
				v.push_back(nums[i]);
			build(0, sz - 1, tot);
			getsum(1);
		}
	}

	void update(int i, int val) {
		int now = 1, dif = val - sgtree[ix[i]].su;
		sgtree[ix[i]].su = val;
		while (sgtree[now].a < sgtree[now].b){
			sgtree[now].su += dif;
			if (i>(sgtree[now].a + sgtree[now].b) >> 1){
				now = sgtree[now].right;
			}
			else
				now = sgtree[now].left;
		}
	}
	int sumRange(int i, int j) {
		return sumhelper(i, j, 1);
	}
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);