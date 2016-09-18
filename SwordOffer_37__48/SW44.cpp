class Solution {
public:
    string ReverseSentence(string str) {
        int sz = str.size();
        if (sz == 0) return "";
        string ret;
        int i = sz - 2, j = sz - 1;
        while (i >= 0){
            while (i >= 0 && str[i] != ' ')--i;
            ret += str.substr(i + 1, j - i);
            if (i >= 0) ret += ' ';
            --i;
            j = i;
        }
        return ret;
    }
};