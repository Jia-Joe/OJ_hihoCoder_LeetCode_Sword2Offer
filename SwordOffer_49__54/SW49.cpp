class Solution {
public:
    int StrToInt(string str) {
        for (int i = 0; i < str.size(); ++i){
            if (!(str[i] >= '0'&&str[i] <= '9' || str[i] == '+' || str[i] == '-' || str[i] == '.' || str[i] == ' '))
                return 0;
        }        
        long long sum=0,cnt=0,i=0;
        int sz=str.size();
        bool zerobegin=true,neg=false;
        while(str[i]==' ') i++;
        if(str[i]=='+') i++;
        else if(str[i]=='-') {i++; neg=true;}
        
        for(;i<sz&&str[i]>='0'&&str[i]<='9';i++){
            if(str[i]=='.') break;
            if(zerobegin&&str[i]=='0')
                continue;
            else
                zerobegin=false;
            sum=(sum<<3)+(sum<<1)+str[i]-48;
            cnt++;
        }
        
        
        if(neg){
            if(-sum<INT_MIN||cnt>10)
                return INT_MIN;
            else
                return -sum;
        }
        else{
            if(sum>INT_MAX||cnt>10)
                return INT_MAX;
            else
                return sum;
        }        
    }
};