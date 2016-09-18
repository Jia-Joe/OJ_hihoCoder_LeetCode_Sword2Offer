class Solution {
public:
    string LeftRotateString(string str, int n) {
        int sz = str.size();
        if (!sz) return "";
        int k=n%sz;
        return str.substr(k, sz-k) + str.substr(0, k);
    }
};

/*
reverse:
"abcdefg" LeftRotateString 3bits
(1)cba defg
(2)cba gfed
(2)defgabc
*/