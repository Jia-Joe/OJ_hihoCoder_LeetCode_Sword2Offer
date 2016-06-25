class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        if(nums.size()==0) return ret;  
        if(nums.size()==1){
            ret.push_back(itos(nums[0]));
            return ret;
        }
        int cnt=0,fi=nums[0];
        
        for(int i=1;i!=nums.size();i++){
            if(nums[i]!=nums[i-1]+1){
                if(cnt==0){
                    ret.push_back(itos(nums[i-1]));
                }
                else{
                    ret.push_back(itos(fi)+"->"+itos(nums[i-1]));
                }
                fi=nums[i];
                cnt=0;
            }
            else{
                cnt++;
            }
            if(i==nums.size()-1){
                if(cnt==0){
                    ret.push_back(itos(nums[i]));
                }
                else{
                    ret.push_back(itos(fi)+"->"+itos(nums[i]));
                }                
            }

        }

            
        
        return ret;
    }
    string itos(int x){
        ostringstream o;
        if(o<<x)
            return o.str();
        return "Error";
    }
};