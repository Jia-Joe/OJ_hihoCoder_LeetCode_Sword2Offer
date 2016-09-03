class Solution {
public:
    double myPow(double x, int n) {
    	bool neg = false;
    	int w=n;
    	//if (x == 0 && n == 0) return 0.0 / 0.0;
    	if (n<0){
    		neg = 1;
    		if (n == INT_MIN) n = INT_MAX;
    		else
    			n = -n;
    	}
    	double y = n & 1 ? x : 1, xt = x;
    	while(n){
    		n >>= 1;
    		xt *= xt;
    		if (n & 1) y *= xt;
    	}
    	if (neg) {
    		if (w == INT_MIN)
    			y *= x;
    		return 1.0 / y;
    	}
    	else return y;
    }
};