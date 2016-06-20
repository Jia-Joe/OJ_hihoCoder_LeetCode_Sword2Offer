class Solution {
public:
    int reverse(int x) {
        long ret = 0, xt=x;
        while (xt)
        {
            ret = ret*10+xt%10;
            xt/=10;
        }
        if (x>0)
            return ret > INT_MAX ? 0 : ret;
        else return ret < INT_MIN ? 0 : ret;
    }
};