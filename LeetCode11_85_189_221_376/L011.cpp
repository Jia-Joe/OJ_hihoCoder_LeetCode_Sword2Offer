class Solution {
public:
    int maxArea(vector<int>& height) {
        int sz=height.size(),p=0,q=sz-1,t,ret=min(height[p],height[q])*(q-p);;
        
        while(p<q){
            int tp=height[p],tq=height[q];
            if(height[p]<height[q]){
                while(p<q&&tp>=height[++p]){
                }
                if(p<q){
                    tp=height[p];
                    t=min(tp,height[q])*(q-p);
                    if(ret<t) ret=t;
                }    
            }
            else{
                while(q>p&&tq>=height[--q]){
                }
                if(q>p){
                    tq=height[q];                
                    t=min(height[p],tq)*(q-p);
                    if(ret<t) ret=t;
                }    
            }
        }
        return ret;
    }
};