class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size(), mi, ret = 0;
    	for (int i = 0; i<sz;){
    		mi = prices[i];
    		int k = i;
    		while (k + 1<sz&&prices[k + 1]>prices[k])
    			++k;
    		if (k>i){
    			ret += prices[k] - mi;
    			i = k+1;
    		}
    		else
    			++i;
    	}
    	return ret;
    }
};