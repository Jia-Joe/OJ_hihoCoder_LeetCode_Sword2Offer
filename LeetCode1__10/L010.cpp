class Solution {
public:
    bool isMatch(string s, string p) {
    	int sz = s.size(), pz = p.size();
    	if (sz == 0){
    		if (pz == 0) return true;
    		bool ret = false;
    		if (pz % 2 == 0) {
    			ret = true;
    			for (int i = 1; i < pz; i+=2){
    				if (p[i] != '*'){
    					ret = false;
    					break;
    				}
    			}
    		}
    		return ret;
    	}
    	if (pz == 0) return false;
    	if (p[pz - 1] == '.' || p[pz - 1] == s[sz - 1])
    		return isMatch(s.substr(0, sz - 1), p.substr(0, pz - 1));
    	else if (p[pz - 1] == '*'){
    		if (p[pz - 2] == '.' || p[pz - 2] == s[sz - 1])
    			return isMatch(s.substr(0, sz), p.substr(0, pz - 2)) || isMatch(s.substr(0, sz - 1), p.substr(0, pz - 2)) || isMatch(s.substr(0, sz - 1), p.substr(0, pz));
    		else
    			return isMatch(s.substr(0, sz), p.substr(0, pz - 2));
    	}
    	else
    		return false;
    }
};