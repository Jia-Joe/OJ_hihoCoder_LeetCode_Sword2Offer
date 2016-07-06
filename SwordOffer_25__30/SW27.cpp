class Solution {
public:
    void swap(string &s, int a, int b){
        char t = s[a]; s[a] = s[b]; s[b] = t;
    }
    void perm(vector<string> &v, string &s, int p, int q){
        if (p >= q) {
            v.push_back(s);
            return;
        }
        for (int i = p; i <= q; ++i){
            swap(s, i, p);
            perm(v, s, p+1, q);
            swap(s, i, p);
        }
    }
    vector<string> Permutation(string str) {
        vector<string> ret;
        if (str.size() == 0) return ret;
        perm(ret, str, 0, str.size() - 1);
        sort(ret.begin(), ret.end());
        vector<string>::iterator it = unique(ret.begin(), ret.end());
        ret.erase(it, ret.end());
        return ret;
    }
};