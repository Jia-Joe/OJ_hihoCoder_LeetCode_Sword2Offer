class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    	int ret = 0, sz = heights.size(),rt;
    	if (sz == 0) return 0;
    	heights.push_back(0);
    	stack<int> st;
    	vector<int> ad(sz + 1, 0);
    	for (int i = 0; i <= sz; i++){
    		int pn = heights[i];
    		if (st.empty() || pn > heights[st.top()]){
    			st.push(i);
    		}
    		else{
    			while (!st.empty()&&heights[st.top()] > pn){
    				int k = st.top();
    				st.pop();
    				if (st.empty()){
    					rt = i*heights[k];
    					if (ret < rt) ret = rt;
    					break;
    				}				
    				int j = st.top();
    				rt = (i - j - 1)*heights[k];
    				if (ret < rt) ret = rt;
    			}
    			st.push(i);
    		}
    	}
    	return ret;
    }
};