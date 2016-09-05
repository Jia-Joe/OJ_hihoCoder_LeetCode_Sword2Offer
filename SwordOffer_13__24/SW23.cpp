class Solution {
public:
    bool ok(vector<int> &v, int p, int q){
        if (p >= q) return true;
        int i=p;
        while (i < q&&v[i] < v[q]) i++;
        for (int j = i ; j <= q;j++)
            if (v[j] < v[q]) 
                return false;
        return ok(v, p, i-1) && ok(v, i, q - 1);
    }

    bool VerifySquenceOfBST(vector<int> sequence) {
        int sz = sequence.size();
        if (sz == 0) return false;
        return ok(sequence, 0, sz-1);
    }
       
};
class Solution {
public:
    typedef unordered_map<int, int> uom;
    bool ok(vector<int> v, vector<int> s, uom mv, uom ms, int v1, int v2, int s1, int s2){
        int ism = ms[v[v2]];
        if (ism<s1 || ism>s2) return false;
        if (v2 == v1) return true;
        int n1 = v1 + ism - s1 - 1;
        if (ism == s1){
            return ok(v, s, mv, ms, n1 + 1, v2 - 1, ism+1, s2);
        }
        else if (ism == s2){
            return ok(v, s, mv, ms, v1, n1, s1, ism-1);
        }
        else{
            return ok(v, s, mv, ms, v1, n1, s1, ism-1) && ok(v, s, mv, ms, n1 + 1, v2 - 1, ism + 1, s2);
        }
    }
    bool VerifySquenceOfBST(vector<int> sequence) {
        int sz = sequence.size();
        if (sz == 0) return false;
        vector<int> st = sequence;
        sort(st.begin(), st.end());
        uom mv, ms;
        for (int i = 0; i < sz; i++){
            mv[sequence[i]] = i;
            ms[st[i]] = i;
        }
        return ok(sequence, st, mv, ms, 0, sz - 1, 0, sz - 1);
    }
       
};