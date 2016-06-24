class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> st;
        for(int i=0;i<nums.size();i++){
            if(st.find(nums[i])!=st.end()&&i-st.find(nums[i])->second<=k)
                return true;
            st[nums[i]]=i;
        }
        return false;
    }
};