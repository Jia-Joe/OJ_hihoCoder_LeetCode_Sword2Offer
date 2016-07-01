class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> v(amount+1,amount+1);
		v[0]=0;
		int sz=coins.size();
		for(int i=1;i<=amount;i++){
			for(int j=0;j<sz;j++){
				if(i-coins[j]>=0&&v[i-coins[j]]+1<v[i]){
					v[i]=v[i-coins[j]]+1;
				}
			}
		}
		
		return v[amount]>amount? -1:v[amount];
    }
};