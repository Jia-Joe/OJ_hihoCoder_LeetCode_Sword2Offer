class Solution {
public:
    int bis(vector<int> v,int i,int j,int w) {
        int p=i,q=j,x;
        while(p<=q){
            x=((q-p)>>1)+p;
            if(v[x]==w)
                return x;
            else if(w<v[x]) q=x-1;
            else p=x+1;   
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        int sz=numbers.size(),i=0,j=0;
        bool f=false;
        for(i=0;i<sz;i++){
            int tg=target-numbers[i];
            j=bis(numbers,i+1,sz-1,tg);
            if(j!=-1) break;
        }
        vector<int> v={i+1,j+1};
        return v;
    }
};