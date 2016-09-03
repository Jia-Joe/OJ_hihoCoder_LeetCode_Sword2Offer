class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	int ret = 0, p1 = 0, p2 = 0, cad;
    	set<char> st;
    	while(p1<s.size()&&p2<s.size()){
    		if (st.find(s[p2]) == st.end()){
    			st.insert(s[p2++]);
    			ret=max(ret,p2-p1);
    		}
    		else{
    		    st.erase(st.find(s[p1++]));
    		}
    	}
    	return ret;
    }
};