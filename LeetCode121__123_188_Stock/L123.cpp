//O(n*k) 12 ms
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return k_maxProfit(2,prices);
    }
    int k_maxProfit(int k, vector<int>& prices) {
    	int sz = prices.size(), ans = 0, i = 1, kc = 0, mi = 0, ma = 0, vgmi=INT_MAX,gmi=0;
    	int *h = new int[2 * k + 2], *e = new int[2 * k + 1], ih = 0, ie = 0;
    	if (k == 0) return 0;
    	while (i < sz){
    		while (i < sz&&prices[i] <= prices[i - 1]) ++i;
    		if (i == sz) break;
    		mi = i - 1;
    		while (i < sz&&prices[i] > prices[i - 1]) ++i;
    		ma = i - 1;
    
    		if (vgmi > prices[mi]) {
    			gmi = mi; vgmi = prices[gmi];
    		}
    		if (ie==0){
    			e[ie] = prices[ma] - vgmi;
    		}
    		else{
    			e[ie] = h[ih - 1] - vgmi;
    			e[ie+1] = prices[ma] - vgmi;
    		}
    		h[ih] = vgmi; h[ih+1] = prices[ma];
    		ans += prices[ma] - vgmi;
  
    		if (kc == k){
    			int emin = INT_MAX, iex = 0;
    			for (int ix=0 ; ix < 2 * k + 1; ++ix){
    				if (emin>e[ix]) {
    					emin = e[ix];
    					iex = ix;
    				}
    			}
    			if (emin < 0) return -12345;
    			ans -= emin;
    			if (iex == 2 * k) continue;
    			if (iex != 0){
    				e[iex - 1] = abs(h[iex + 2] - h[iex - 1]);
    			}
    			for (int j = iex; j < 2 * k - 1; j++){
    				e[j] = e[j + 2];
    				h[j] = h[j + 2];
    			}
    			h[2 * k - 1] = h[2 * k + 1];
    			
    		}
    		else ++kc;
    		ie = 2 * kc - 1;
    		ih = 2 * kc;
    		vgmi = INT_MAX;
    	}
    	return ans;
    }
};

int maxProfit(int k, vector<int>& prices) {
	int sz = prices.size(), ans = 0, i = 1, kc = 0, mi = 0, ma = 0, vgmi=INT_MAX,gmi=0;
	int *h = new int[2 * k + 2], *e = new int[2 * k + 1], ih = 0, ie = 0;
	if (k == 0) return 0;
	while (i < sz){
		while (i < sz&&prices[i] <= prices[i - 1]){
			++i;
			//if (mi>prices[i]) mi = prices[i];
		}
		if (i == sz) break;
		mi = i - 1;
		while (i < sz&&prices[i] > prices[i - 1]){
			++i;
		}
		ma = i - 1;

		if (vgmi > prices[mi]) {
			gmi = mi; vgmi = prices[gmi];
		}
		if (ie==0){
			e[ie] = prices[ma] - vgmi;
		}
		else{
			e[ie] = h[ih - 1] - vgmi;
			e[ie+1] = prices[ma] - vgmi;
		}
		
		h[ih] = vgmi; h[ih+1] = prices[ma];
		cout << "ans:" << ans <<"+" <<prices[ma] << "-" << vgmi << "=" ;
		ans += prices[ma] - vgmi;
		cout << ans << endl;
		
		//cout << "e:";
		//for (int i = 0; i < 2 * k + 1; i++)
		//	cout << e[i] << " ";
		//cout << endl;
		//cout << "h:";
		//for (int i = 0; i < 2 * k + 2; i++)
		//	cout << h[i] << " ";
		//cout << endl;
		
		if (kc == k){
			int emin = INT_MAX, iex = 0;
			for (int ix=0 ; ix < 2 * k + 1; ++ix){
				if (emin>e[ix]) {
					emin = e[ix];
					iex = ix;
				}
			}
			if (emin < 0) return -12345;
			cout << "ans:" << ans << "-" << emin << "=";
			ans -= emin;
			cout << ans << endl;
			//Shrink hPoint from 2k+2 to 2k, Edge from 2k+1 to 2k-1
			if (iex == 2 * k) continue;
			if (iex != 0){
				e[iex - 1] = abs(h[iex + 2] - h[iex - 1]);
			}
			for (int j = iex; j < 2 * k - 1; j++){
				e[j] = e[j + 2];
				h[j] = h[j + 2];
			}
			h[2 * k - 1] = h[2 * k + 1];
			
		}
		else ++kc;
		ie = 2 * kc - 1;
		ih = 2 * kc;
		vgmi = INT_MAX;
	}
	return ans;
}