class Solution {
public:
    int rob(vector<int>& nums) {
        int sz=nums.size(),m[2000],m_1[2000];
        if(sz==0) return 0;
        if(sz==1) return nums[0];
        if(sz==2) return max(nums[0],nums[1]);
        m[0]=nums[0];m_1[0]=0;
        m[1]=nums[1];m_1[1]=nums[0];
        for(int i=2;i<sz;i++){
            m_1[i]=max(m[i-2],m[i-1]);
            m[i]=m_1[i-1]+nums[i];
        }
        return max(m[sz-2],m[sz-1]);
    }

};
//O(1)space solution
class Solution {
public:
    int rob(vector<int>& nums) {
        int a1 = 0, a2 = 0, a3 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int temp = max(a1, a2) + nums[i];
            a1 = a2;
            a2 = a3;
            a3 = temp;
        }
        return max(a2, a3);
    }
};