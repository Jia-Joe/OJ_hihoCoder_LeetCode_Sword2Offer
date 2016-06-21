class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int sn=strs.size();
        if(sn==0) return ""; 
        int miz=strs[0].size(),ret=0;
        for(int i=1;i<sn;i++){
            if(strs[i].size()<miz)
                miz=strs[i].size();
        }

        for(int i=0;i<miz;i++){
            int j=0;
            for(;j<sn;j++){
                if(strs[j][i]!=strs[0][i])
                    break;
            }
            if(j==sn)
                ret++;
            else
                break;
        }
        return strs[0].substr(0,ret);
    }
};