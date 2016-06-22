class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()!=0 && haystack.size()==0) return -1;
        int *next=new int[needle.size()];
        const char* s=haystack.c_str(),*p=needle.c_str();
        GetNext(p, next);
        return KMP(s,p,next);
    }
    int KMP(const char *s, const char *p,int *next) 
    {
    	int i = 0, j = 0, sz=strlen(s), pz=strlen(p);
    	while (i < sz&&j < pz) {
    		int h = i;
    		if (s[i] == p[j]||j==-1){
    			i++; j++;
    		}
    		else j = next[j];
    	}
    	if (j<pz) return -1;
    	else return i - j;
    
    }  
    void GetNext(const char* s, int next[]){
    	int sz = strlen(s), i = 0, j = -1;
    	next[0] = -1;
    	while (i < sz - 1){
    		if (j == -1 || s[i] == s[j]){
    			i++; j++;
    			next[i] = j;
    		}
    		else{
    			j = next[j];
    		}
    	}
    }
    
};