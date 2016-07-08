class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int sz = A.size();
        vector<int> v;
        int *a = new int[sz], *b = new int[sz];
        if (sz < 2) return v;
        int x = 1, y = 1;
        for (int i = 0; i < sz; ++i){
            x *= A[i];
            y *= A[sz - 1 - i];
            a[i] = x;
            b[sz - 1 - i] = y;
        }
        v.push_back(b[1]);
        for (int i = 1; i < sz-1; ++i){
            v.push_back(a[i-1]*b[i+1]);
        }
        v.push_back(a[sz - 2]);
        return v;
    }
};