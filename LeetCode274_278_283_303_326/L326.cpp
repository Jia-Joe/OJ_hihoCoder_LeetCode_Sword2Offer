//Without using any loop / recursion
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
    	double x = n, y = log10(x) / log10(3);
    	return fabs(y - round(y))==0;
    }
};

class Solution {
public:
    bool isPowerOfThree(int n) {
        double x=n,y=log(x)/log(3);
        return fabs(y-round(y))<1e-10;
    }
};

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        int t = pow(3,(int)(log(INT_MAX)/log(3)));
        return t%n == 0;
    }
};