class Solution {
public:
	priority_queue<int,vector<int>,less<int>> ma;
	priority_queue<int,vector<int>,greater<int>> mi;

	void Insert(int num)
	{
		if (ma.empty()||num > ma.top()) mi.push(num);
		else ma.push(num);
		if (ma.size() > mi.size() + 1){
			mi.push(ma.top());
			ma.pop();
		}
		if (mi.size() > ma.size() + 1){
			ma.push(mi.top());
			mi.pop();
		}
	}

	double GetMedian()
	{
		if (ma.size() == mi.size())
			return (ma.top() + mi.top()) / 2.0;
		else if (ma.size() > mi.size())
			return ma.top();
		else
			return mi.top();
	}

};

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