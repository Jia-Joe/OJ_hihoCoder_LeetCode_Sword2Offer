class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        unordered_map<char, int> mp;
        for (int i = 0; i < str.size(); ++i){
            if (mp.find(str[i]) == mp.end())
                mp[str[i]] = i;
            else
                mp[str[i]] = INT_MAX;
        }
        int ret = INT_MAX;
        for (pair<char,int> pa : mp){
            if (ret>pa.second)
                ret = pa.second;
        }
        return ret == INT_MAX ? -1 : ret;
    }
};