class Solution {
public:
    int GetNumberOfK(vector<int> data, int k) {
        int ans = 0, sz = data.size(), p = 0,q=sz-1,m=0;
        if (sz == 0) return 0;
        while (p <= q){
            m = (p + q) >> 1;
            if (data[m] == k) {
                ans++; break;
            }
            else if (data[m] < k) p = m + 1;
            else q = m - 1;
        }
        if (p>q) return 0;
        int t = m;
        while (--t >= 0 && data[t] == k) ans++;
        t = m;
        while (++t < sz && data[t] == k) ans++;
        return ans;
    }
};