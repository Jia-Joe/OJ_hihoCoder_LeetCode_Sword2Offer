class NumArray {
public:
    vector<int> v;
    NumArray(vector<int> &nums) {
        for(int i=0;i<nums.size();i++)
            v.push_back(nums[i]);
    }

    int sumRange(int i, int j) {
        int ret=0;
        for(int w=i;w<=j;w++){
            ret+=v[w];
        }
        return ret;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);