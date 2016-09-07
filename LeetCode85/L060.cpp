class Solution {
public:
    string getPermutation(int n, int k) {
        string res(n,'1');
        vector<int> v(n);
        int w=0,p=1;
        for(int i=0;i<n;i++){
            v[i]=i;
            if(i!=n-1) p*=i+1;
        }
        
        k--;
        for(int i=n-1;i>0;i--){
            int r=k/p;
            res[w++]='1'+v[r];
            v.erase(v.begin()+r);
            k=k%p;
            p/=i;
        }
        res[w]='1'+v[0];
        return res;
    }
};