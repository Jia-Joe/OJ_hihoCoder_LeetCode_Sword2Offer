class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int sz=nums.size(),k=1,re=2;
        if(sz==0) return 0;
        while(k<sz&&nums[k]==nums[k-1]) k++;
        if(k==sz) return 1;
        bool f=nums[k]>nums[k-1];
        for(int i=k+1;i<sz;i++){
            if(nums[i]>nums[i-1]&&!f){
                f=1;
                re++;
                
            }
            else if(nums[i]<nums[i-1]&&f){
                f=0;
                re++;
            }
            else continue;
        }
        return re;
    }
};