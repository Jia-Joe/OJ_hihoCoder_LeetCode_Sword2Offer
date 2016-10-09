class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> re;
        int sz=strs.size(),n=0;
        unordered_map<string,int> st;
        for(int i=0;i<sz;i++){
            string s=strs[i];
            sort(s.begin(),s.end());
            auto it=st.find(s);
            if(it==st.end()){
                st[s]=n++;
                re.push_back(vector<string>(1,strs[i]));
            }
            else{
                re[it->second].push_back(strs[i]);
            }
        }
        return re;
    }
};