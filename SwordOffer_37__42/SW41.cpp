class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> >v;
        if (sum < 3) return v;
        sum <<= 1;
        int sz = sqrt(sum);
        for (int i = 2; i <= sz; ++i){
            if (sum%i == 0){
                int j = sum / i;
                if ((i + j) % 2 == 1){
                    int x = (j - i + 1) >> 1, y = (j + i - 1) >> 1;
                    vector<int> t;
                    for (int k = x; k <= y; ++k)
                        t.push_back(k);
                    v.push_back(t);
                }
            }
        }
        sort(v.begin(), v.end());
        return v;
    }
};

vector<vector<int> > FindContinuousSequence(int sum) {
	vector<vector<int> > res;
	sum <<= 1;
	for (int i = 2; i * i <= sum; ++i) if (sum % i == 0){
		int j = sum / i, t = (j - i + 1);
		if (!(t & 1)){
			res.push_back(vector<int>());
			vector<int>& v = res[res.size() - 1];
			t >>= 1;
			for (int a = t; a <= j - t; ++a) v.push_back(a);
		}
	}
	reverse(res.begin(), res.end());
	//for (int i = 0, j = int(res.size()) - 1; i < j; ++i, --j) swap(res[i], res[j]);
	return res;
}