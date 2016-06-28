// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n==1) return 1;
        int p=1,q=n;
        while(p<=q){
            if(isBadVersion(p)&&isBadVersion(q)) return p;
            if(!isBadVersion(p)&&!isBadVersion(q)) return q+1;
            if(q-p==1) return q;
            
            int m=p+(q-p>>1);
            if(!isBadVersion(m)&&isBadVersion(q)){
                p=m+1;
            }
            if(!isBadVersion(p)&&isBadVersion(m)){
                q=m-1;
            }
            
        }
        return -11;
    }
};