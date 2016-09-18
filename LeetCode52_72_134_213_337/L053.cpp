class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size(),r=INT_MIN,s=0;
        vector<int> v(n,0);
        for(int i=n-1;i>=0;i--){
            if(s+nums[i]>=0){
                s+=nums[i];
                v[i]=s;
                if(r<s) r=s;
            }
            else{
                s=0;
                if(r<nums[i]) r=nums[i];
            }
            
        }
        return r;
    }
};