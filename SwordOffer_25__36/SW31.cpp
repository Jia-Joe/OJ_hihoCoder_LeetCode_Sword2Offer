class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int ans = 0;
        for (long long i = 1; i <= n; i *= 10){
            int q = n / i, r = n%i;
            if (q%10==1)
                ans += (q / 10 )*i+r+1;
            else if (q%10==0)
                ans += (q / 10)*i;
            else
                ans += (q / 10 + 1)*i;
        }
        return ans;
    }
};