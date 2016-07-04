class Solution {
public:
    double Power(double base, int exponent) {
        if (base == 0){
            if (exponent>0) return 0;
            else if (exponent==0)return NAN;
            else return INFINITY;
        }
        if (base == 1) return 1;
        int exp = abs(exponent);
        double ret=1,big=base;
        while (exp){
            if(exp & 0x00000001)
                ret*=big;
            exp >>= 1;
            big = big*big;
        }
        return exponent>=0? ret:1/ret;
    }
};