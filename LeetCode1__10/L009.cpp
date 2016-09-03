class Solution {
public:
    bool isPalindrome(int x) {
    	if (x<0)
    		return false;
    	int xt = x, ndig = 0;
    	while (xt != 0){
    		xt /= 10;
    		ndig++;
    	}
    	bool ret = true;
    	for (int i = 0; i<ndig / 2; i++){
    		int t = ndig - 1 - i;
    		if (x / int(pow(10, i)) % 10 != x / int(pow(10, t)) % 10){
    			ret = false;
    			break;
    		}
    
    	}
    	return ret;        
    }
};