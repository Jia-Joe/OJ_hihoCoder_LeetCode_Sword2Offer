int numTrees(int n) {
        return Comb(2*n,n)/(n+1);
    }
    long long Comb(int n,int k){
        if(n<2) return 1;
        long long *p=new long long[2*n];
        p[0]=1;p[1]=1;
        for(int i=2;i<n+1;++i){
            long long *t=new long long[1+i];
            t[i]=1;
            for(int j=1;j<i;j++)
                t[j]=p[j]+p[j-1];
            for(int j=1;j<i+1;j++)
                p[j]=t[j];
            delete[] t;
        }
        return p[k];
    }