class Solution {
public:

    int maxProfit(int k, vector<int>& prices) {
    	if (k == 0) return 0;
    	multimap<int,list<int>::iterator> e;
    	typedef multimap<int, list<int>::iterator>::iterator mpit;
    	list<int> h; 
    	typedef pair<int, list<int>::iterator> pa;
    	mpit ie1,ie2,it1,it2; list<int>::iterator ih,i1,i2;
    	int sz = prices.size(), ans = 0, i = 1, kc = 0, mi = 0, ma = 0, vgmi = INT_MAX, gmi = 0;
    	bool fi = true;
    	while (i < sz){
    		while (i < sz&&prices[i] <= prices[i - 1]){
    			++i;
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
    		h.push_back(vgmi);
    		h.push_back(prices[ma]); ih = --h.end();
    		if (fi){
    			e.insert(make_pair(prices[ma] - vgmi, ih));
    			fi = false;
    		}
    		else{
    			i1 = ----ih; i2 = ++ih;
    			e.insert(make_pair(*(i1) - vgmi, i2));
    			e.insert(make_pair(prices[ma] - vgmi, ++ih));
    		}
    		ans += prices[ma] - vgmi;
    
    
    		if (kc == k){
    			mpit iex = min_element(e.begin(), e.end(), [](pa e1,pa e2) {return e1.first<e2.first; });
    			//mpit iex;// = min_element(e.begin(), e.end());
    			list<int>::iterator ihx = iex->second;
    			int ex = iex->first;
    			ans -= ex;
    			//Shrink hPoint from 2k+2 to 2k, Edge from 2k+1 to 2k-1
    			e.erase(iex);
    			if (ihx == --h.end()) {			
    				i1 = ----ihx; i2 = ++ihx;
    				ie1 = e.lower_bound(*i1 - *i2);
    				ie2 = e.upper_bound(*i1 - *i2);
    				for (mpit iet = ie1; iet != ie2; ++iet){
    					if (iet->second == ihx){
    						e.erase(iet); break;
    					}
    				}
    				ihx=h.erase(i2); h.erase(ihx);
    			}
    			else{
    				if (ihx == ++h.begin()){
    					i1 = ihx; i2 = ++ihx;
    					ie1 = e.lower_bound(*i1 - *i2);
    					ie2 = e.upper_bound(*i1 - *i2);
    					for (mpit iet = ie1; iet != ie2; ++iet){
    						if (iet->second == ihx){
    							e.erase(iet); break;
    						}
    					}
    					ihx=h.erase(--ihx); h.erase(--ihx);
    					
    				}
    				else{
    					i1 = --ihx; i2 = --ihx;
    					ie1 = e.lower_bound(abs(*i1 - *i2));
    					ie2 = e.upper_bound(abs(*i1 - *i2));
    					++ihx;
    					for (mpit iet = ie1; iet != ie2; ++iet){
    						if (iet->second == ihx){
    							e.erase(iet); break;
    						}
    					}
    					i1 = ++ihx; i2 = ++ihx;
    					ie1 = e.lower_bound(abs(*i1 - *i2));
    					ie2 = e.upper_bound(abs(*i1 - *i2));
    					for (mpit iet = ie1; iet != ie2; ++iet){
    						if (iet->second == ihx){
    							e.erase(iet); break;
    						}
    					}
    					i1 = ihx; i2 = ------ihx;
    					e.insert(make_pair(abs((*i1)-(*i2)), ++++++ihx));
    					ihx = h.erase(--ihx); h.erase(--ihx);
    				}
    				vgmi = INT_MAX;
    			}
    		}
    		else {
    			++kc; vgmi = INT_MAX;
    		}
    	}
    	return ans;
    }
    
};