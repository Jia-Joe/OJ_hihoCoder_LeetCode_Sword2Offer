//DP
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> v) {
        if (v.size()==0) return 0;
        int ma = INT_MIN;
        for (int i = 0, su = 0; i < v.size(); ++i){
            su = max(su + v[i], v[i]);
            ma = max(ma, su);
        }
        return ma;
    }
};

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int sz = array.size(), i = 0, j = 0, k = 0, ret = INT_MIN,su=0, mi = 0, ma=0;
        if(sz==0) return 0;
        while (i < sz){
            while (i<sz&&array[i] < 0){
                mi += array[i];
                ++i;
            }
            while (i<sz&&array[i] >= 0){
                ma += array[i];
                ++i;
            }

            if (mi+ma>=0||ma>=0){
                su = su + mi + ma;
                if (su > ma){
                    if (su > ret) ret = su;
                }
                else {
                    if (ma > ret) ret = ma;
                    su = ma;
                }
            }
            else su = 0;
            mi = 0; ma = 0;

        }
        if (ret == 0) return *max_element(array.begin(), array.end());
        return ret;
    }
};