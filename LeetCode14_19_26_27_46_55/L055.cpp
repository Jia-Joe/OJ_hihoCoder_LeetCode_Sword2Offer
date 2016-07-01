//O(n)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int nz=nums.size();
        int maxs=nums[0];
        for(int i=1;i<=maxs;i++){
            if(i+nums[i]>maxs)
                maxs=i+nums[i];
            if(maxs>=nz-1)
                break;
        }
        
        if(maxs>=nz-1)
            return true;        
        else 
            return false;
    }
};

//O(n^2)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int nz=nums.size();
        bool ok[100000];
        ok[0]=true;
        for(int i=1;i<nz;i++){
            bool f=false;
            for(int j=i-1;j>=0;j--){
                if(ok[j]&&nums[j]+j>=i){
                    f=true;
                    break;
                }
            }
            ok[i]=f;
        }
        
        return ok[nz-1];
    }
};