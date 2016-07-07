//priority_queue<int, vector<int>, greater<int> > v;
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        int sz = log2(INT_MAX) + 1;
        vector<int> v;
        long long x = 1, y = 1, z = 1;
        for (int i = 0; i < sz; ++i){
            if (i == 0) x = 1;
            else x *= 2;
            if (x>INT_MAX) break;
            for (int j = 0; j < sz; ++j){
                if (j == 0) y = 1;
                else y *= 3;
                if (x*y>INT_MAX) break;
                for (int k = 0; k < sz; ++k){
                    if (k == 0) z = 1;
                    else z *= 5;
                    long long t = x*y*z;
                    if (t>INT_MAX) break;
                    else
                        v.push_back(t);
                }
            }
        }
        sort(v.begin(), v.end());
        unordered_map<int, int> um;
        for (int i = 0; i < v.size(); ++i)
            um[i] = v[i];
        return um[index - 1];
    }
};