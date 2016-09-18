class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        vector<int> ret;
        int sz = array.size(), i = 0, j = sz - 1;
        int di[3] = { 0, 1, 0 }, dj[3] = { 0, 0, -1 };
        if (sz < 2) return ret;
        while (i < j){
            int su = array[i] + array[j];
            if (su == sum){
                ret.push_back(array[i]);
                ret.push_back(array[j]);
                return ret;
            }
            else if (su < sum) ++i;
            else --j;
        }

        return ret;
    }
};