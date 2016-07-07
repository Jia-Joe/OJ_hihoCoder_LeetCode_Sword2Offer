class Solution {
public:
    void mergesort(vector<int> &v, int p, int q, int &t){
        if (p == q) return;
        int m = (p + q) >> 1,i,j;
        mergesort(v, p, m,t);
        mergesort(v, m + 1, q,t);
        vector<int> vb;
        int w = 0;
        for (i = p, j = m + 1; i <= m&&j <= q;){
            if (v[i] <= v[j]){
                vb.push_back(v[i]); ++i;
                t += w;
            }
            else{
                vb.push_back(v[j]); ++j;
                ++w;
            }
        }
        if (i > m)while (j <= q) vb.push_back(v[j++]);
        else if (j > q){
            while (i <= m){
                cout << "vi:" << v[i] << endl;
                vb.push_back(v[i++]);
                t += w;
            }
        }
        for (int i = p; i <= q; ++i)
            v[i] = vb[i - p];
    }
    int InversePairs(vector<int> data) {
        if (data.size() == 0) return 0;
        int ans = 0;
        mergesort(data, 0, data.size() - 1, ans);
        return ans;
    }
};


void mergesort(vector<int> &v, int p, int q){
	if (p == q) return;
	int m = (p + q) >> 1,i,j;
	mergesort(v, p, m);
	mergesort(v, m + 1, q);
	vector<int> vb;
	for (i = p, j = m + 1; i <= m&&j <= q;){
		if (v[i] < v[j]){
			vb.push_back(v[i]); ++i;
		}
		else{
			vb.push_back(v[j]); ++j;
		}
	}
	if (i > m)while (j <= q) vb.push_back(v[j++]);
	else while (i <= m) vb.push_back(v[i++]);
	for (int i = p; i <= q; ++i)
		v[i] = vb[i - p];
}