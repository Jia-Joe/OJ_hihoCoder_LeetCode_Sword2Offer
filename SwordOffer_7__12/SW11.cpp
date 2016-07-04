class Solution {
public:
    int  NumberOf1(int n) {
        int ret = 0;
        if (n < 0) ret++;
        n &= 0x7FFFFFFF;
        while (n){
            ret += n & 0x00000001;
            n >>= 1;
        }
        return ret;
    }
};