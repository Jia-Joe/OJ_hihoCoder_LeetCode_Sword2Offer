class Solution {
public:
    bool isInt(char* s, int &fi, int q, bool &dot){
        if (fi > q) return false;
        for (; fi <= q; fi++){
            if (s[fi] == ' ') continue;
            if (s[fi] == '.') dot = true;
            if (!(s[fi] >= '0'&&s[fi] <= '9') && s[fi] != '+'&&s[fi] != '-'&&s[fi] != '.') {
                return false;
            }
            else  break;
        }
        if (fi+1 > q && (s[fi] < '0'||s[fi] > '9')) return false;
        fi++;
        return true;
    }
    bool isNumeric(char* string)
    {
        int sz = strlen(string);
        if (sz == 0) return false;
        int fi=0;
        char *s = string;
        bool dot = false, ep = false;
        if (!isInt(s, fi, sz - 1,dot)) return false;


        for (; fi < sz; fi++){
            if (dot){
                if (!(s[fi] >= '0'&&s[fi] <= '9') && s[fi] != 'e'&&s[fi] != 'E') return false;
            }			
            else{
                if (!(s[fi] >= '0'&&s[fi] <= '9') && s[fi] != 'e'&&s[fi] != 'E' && s[fi] != '.') return false;
            }			
            if (s[fi] == '.') {
                dot = true;
            }
            if (s[fi] == 'e' || s[fi] == 'E') {
                ep = true; break;
            }
        }
        dot = false;
        if (ep) {
            fi++;
            if(!isInt(s, fi, sz - 1,dot)) return false;
            if (dot == true) return false;
            for (; fi <sz ; fi++){
                if (!(s[fi] >= '0'&&s[fi] <= '9')) return false;
            }
        }
        return true;
    }

};