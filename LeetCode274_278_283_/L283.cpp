class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p=0,sz=nums.size();
        for(int i=0;i<sz;i++){
            if(nums[i]!=0){
                swap(nums[i],nums[p]);
                p++;
            }
        }
    }
};