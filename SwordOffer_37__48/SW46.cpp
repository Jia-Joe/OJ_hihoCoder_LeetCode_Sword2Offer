class Solution {
public:
    int LastRemaining_Solution(unsigned int n, unsigned int m)
    {
        if (n < 1 || m < 1) return -1;
        int *a = new int[n];
        for (int i = 0; i < n; ++i)
            a[i]=i;
        int sz = n, i = 0;
        while (sz>1){
            //for (int x = 0; x < sz; x++)
            //	cout << a[x] <<" " ;
            //cout << endl;
            int k = (i + (m-1)%sz) % sz;
            for (int j = k; j < sz-1 ; ++j)
                a[j] = a[j + 1];
            i = k;
            sz--;
        }
        return a[0];
    }
};