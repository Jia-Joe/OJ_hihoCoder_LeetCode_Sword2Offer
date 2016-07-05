class Solution {
public:
    int rectCover(int number) {
        if(number==0) return 0;
        if(number==1) return 1;
        if(number==2) return 2;
        int a=1,b=2;
        for(int i=2;i<number;i++){
            int c=a+b;
            a=b;
            b=c;
        }
        return b;                   
    }
};