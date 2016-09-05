class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ret = 0,yr = matrix.size(); 
	    if (yr == 0) return 0;
	    int xr = matrix[0].size();
	    vector<int> v=vector<int>(xr,0);
	    for(int i=0;i<yr;i++){
	        for(int j=0;j<xr;j++){
	            if(matrix[i][j]=='1') v[j]++;
	            else v[j]=0;
	        }
	        int w=find(v);
	        if(ret<w) ret=w;
	    }
	    return ret;      
    }
    int find(vector<int>& heights) {
    	int ret = 0, sz = heights.size(), rt, i = 0;
    	if (sz == 0) return 0;
    	heights.push_back(0);
    	stack<int> st;
    	while (i < sz + 1){
    		if (st.empty() || heights[i] > heights[st.top()]){
    			st.push(i++);
    		}
    		else{
    			int j = st.top();
    			st.pop();
    			rt = heights[j] * (st.empty() ? i : i - st.top() - 1);
    			if (ret < rt) ret = rt;
    		}
    	}
    	return ret;
    }   
};

//OTHERS
int maximalRectangle(vector<vector<char>>& matrix) {
	int n = (matrix.empty()) ? 0 : matrix[0].size(), res = 0;
	vector<int> left(n, 0), right(n, n), height(n, 0);
	for (auto mat : matrix)
	{
		int lstart = 0, rstart = n;
		for (int j = 0; j<n; ++j)
		{
			height[j] = (mat[j] == '1') ? height[j] + 1 : 0;
			left[j] = (mat[j] == '1') ? max(left[j], lstart) : min(0, lstart = j + 1);
			right[n - j - 1] = (mat[n - j - 1] == '1') ? min(right[n - j - 1], rstart) : max(n, rstart = n - j - 1);
		}
		FOI(n) cout << left[i] << "," << right[i] << "  ";
		cout << endl;
		for (int j = 0; j<n; ++j)
		{
			res = max(res, (right[j] - left[j])*height[j]);
			cout << (right[j] - left[j])*height[j] << "    ";
			
		}
		cout << endl;
	}
	return res;
}