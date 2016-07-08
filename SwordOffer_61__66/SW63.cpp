class Solution {
public:
	vector<int> v;
	int sz=0;
	void Insert(int num)
	{
		v.push_back(num);
		sz++;
		for (int i = sz - 2; i >= 0; --i){
			if (v[i] > v[i + 1]) swap(v[i], v[i + 1]);
			else break;
		}
	}

	double GetMedian()
	{
		if (sz & 1 == 1) return v[sz >> 1];
		else return (v[sz >> 1] + v[(sz >> 1) - 1]) / 2.0;
	}

};