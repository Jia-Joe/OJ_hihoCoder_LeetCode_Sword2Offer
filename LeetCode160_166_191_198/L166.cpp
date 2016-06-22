class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        //c+a/b
        if(numerator==INT_MIN)
            if(denominator==1) return "-2147483648";
            else if(denominator==-1) return "2147483648";
        long long b=llabs(denominator), c=llabs(numerator/b), a=llabs(numerator)%b;
        string ret="";
        if(numerator>0&&denominator<0||numerator<0&&denominator>0) {
            ret.append("-"); 
        }
        long long ct=c,ic=0;
        char ch[11];
        while(ct){
            ch[ic++]=ct%10+48;
            ct/=10;
        }
        ch[ic]='\0';
        for(int i=0;i<ic/2;i++)
            swap(ch[i],ch[ic-1-i]);
        ret.append(ch);
        
        if(c==0) ret.append("0");
        if(a!=0) ret.append(".");
        
        char qv[1000];
        int i=0;
        long long r=a;
        map<long long,int> sre;
        while(r!=0){
            if(sre.find(r)!=sre.end())
                break;
            sre[r]=i;
            r=(r<<3)+(r<<1);
            qv[i++]=r/b+48;
            r=r%b;
        }
        qv[i]='\0';
        if(r==0)
            ret.append(qv);
        else{
            string str(qv);
            int ix=sre.find(r)->second;
            ret.append(str.substr(0,ix));
            ret.append("(");
            ret.append(str.substr(ix,i-ix));
            ret.append(")");
        }
        
        return ret;
    }
};