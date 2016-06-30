class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret=0,mit=INT_MAX;
		for(int i=0;i<prices.size();i++){
			if(prices[i]<mit)
				mit=prices[i];
			else if(prices[i]-mit>ret)
				ret=prices[i]-mit;
		}
		return ret;
    }
};