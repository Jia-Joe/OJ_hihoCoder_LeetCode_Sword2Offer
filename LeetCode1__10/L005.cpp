class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size(),ret=1,pt=0,qt=0;
        string sr;
        for(int i=0;i<n-1;i++){
            for(int p=i,q=i+1;p>=0&&q<n&&s[p]==s[q];p--,q++){
                if(q-p+1>ret){
                    ret=q-p+1;
                    pt=p;
                    qt=q;
                }
            }
            for(int p=i-1,q=i+1;p>=0&&q<n&&s[p]==s[q];p--,q++){
                if(q-p+1>ret){
                    ret=q-p+1;
                    pt=p;
                    qt=q;
                }
            }
        }
        if(ret==1) sr=s.substr(0,1);
        else{
            sr=s.substr(pt,qt-pt+1);
        }
        return sr;
    }
};