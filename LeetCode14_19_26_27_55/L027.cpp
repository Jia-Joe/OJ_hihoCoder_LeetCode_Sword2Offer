class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size(),cnt=0;
        for(vector<int>::iterator it=nums.begin();it!=nums.end();){
            if(*it==val){
                it=nums.erase(it);
                cnt++;
            }
            else
                it++;
        }
        return n-cnt;
    }
};