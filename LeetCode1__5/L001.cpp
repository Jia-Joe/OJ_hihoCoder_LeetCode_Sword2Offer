class Solution {
public:
    //O(NlogN) complexity
    template < typename T>
    vector<size_t> sort_indexes(const vector<T>  & v) {
    	vector<size_t>  idx(v.size());
    	for (size_t i = 0; i != idx.size(); ++i) idx[i] = i;
    	sort(idx.begin(), idx.end(),
    		[&v](size_t i1, size_t i2) {return v[i1] < v[i2]; });
    
    	return idx;
    }
    int bifind(vector<int>& v, vector<size_t> &id, int x, int p)
    {
    	int p1 = p, p2 = v.size() - 1, m;
    
    	while (p1<=p2)
    	{
    		m = p1 + (p2 - p1) / 2;
    		if (v[id[m]] == x)
    			return m;
    		else if (v[id[m]]<x)
    			p1 = m + 1;
    		else
    			p2 = m - 1;
    
    	}

        return -1;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
    	vector<int> re(2);
    	vector<size_t> idx = sort_indexes<int>(nums);
    
    	//sort(nums.begin(), nums.end());
    	for (size_t i = 0; i<nums.size() - 1; i++)
    	{
    		int y = bifind(nums, idx, target - nums[idx[i]], i + 1);
    		if (y != -1)
    		{
    			re[0] = idx[i] < idx[y] ? idx[i] : idx[y];
    			re[1] = idx[y] >= idx[i] ? idx[y] : idx[i];
    			return re;
    		}
    
    	}
    	return re;
    }
};