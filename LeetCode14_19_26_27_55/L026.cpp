class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if (n<2) return n;
        int p1=1,p2=1;
        for(;p2<n;p2++){
            if(nums[p2]!=nums[p2-1]){
                nums[p1]=nums[p2];
                p1++;
            }
        }
        return p1;
    }
};