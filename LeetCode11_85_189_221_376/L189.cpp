class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int sz=nums.size();
        vector<int> v=nums;
        for(int i=0;i<sz;i++){
            nums[(i+k)%sz]=v[i];
        }
    }
};