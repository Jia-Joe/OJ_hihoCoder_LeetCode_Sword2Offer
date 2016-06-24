class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {

        map<long long,int> mp;
        int sz=nums.size(),p=0;
        for(int i=0;i<sz;i++){
            if(i-p>k && mp[nums[p]] == p){
                mp.erase(nums[p++]);
            }
            auto it1 = mp.lower_bound(nums[i]-t),it2 = mp.lower_bound(nums[i]+t);
            if(it1!=mp.end()&&abs(it1->first-nums[i])<=t) return true;
            if(it2!=mp.end()&&abs(it2->first-nums[i])<=t) return true;
            mp[nums[i]]=i;
        
        }
        return false;
    }
};