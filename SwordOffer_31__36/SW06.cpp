class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int sz = rotateArray.size();
        if (sz == 0)return 0;
        if (sz == 1) return rotateArray[0];
        int p = 0, q = sz - 1, m = 0, v = rotateArray[0];
        while (p <= q){
            m = (p + q) >> 1;
            if (rotateArray[m] >= v)
                p = m + 1;
            else
                q = m - 1;
        }
        if (m == 0||m==sz-1) return min(rotateArray[m], rotateArray[m - 1]);
        return min(min(rotateArray[m-1], rotateArray[m]),rotateArray[m+1]);
    }
};