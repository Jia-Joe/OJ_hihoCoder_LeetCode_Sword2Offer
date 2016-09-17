class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sz=s.size(),tz=t.size();
        if(sz>tz) return 0;
        int p=0,q=0;
        while(p<sz&&q<tz){
            if(s[p]==t[q]){
                p++;q++;
            }
            else q++;
        }
        return p==sz;
    }
};